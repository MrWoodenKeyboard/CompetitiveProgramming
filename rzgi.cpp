#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

struct node{
    int dest;
    bool isSuper;
     double percent;
};

vector <vector<node> > adj;
vector <int> need;

void addEdge(int from, int to,  double percent, bool isSuper){
    node temp;
    temp.dest = to;
    temp.percent = percent;
    temp.isSuper = isSuper;
    adj[from].push_back(temp);
}

 double requiredWater(int cNode, bool isSuper,  double percent){
    //if is used to return the required water amount of the leaf nodes directly, making it the abse case of the recursion
//    cout << "entered requiredWater for node " << cNode << endl;
    if(need[cNode] != -1){
//        cout << " this is a leaf node" << endl;
        if(isSuper){
//            cout << "required amount for the leaf node  " << cNode << " with super pipe is: " << sqrt(need[cNode])*100/percent << endl;
            return sqrt(need[cNode])*100/percent;
        }
        else{
//            cout << "required amount for the leaf node " << cNode << " is: " << need[cNode] << endl;
            return need[cNode]*100/percent;
        }
    }

     double amount = 0;
     double amountForChild;
    //calculating the required water amounts for each child recursively and taking the max
    for(int i = 0; i < adj[cNode].size(); i++){
        amountForChild = requiredWater(adj[cNode].at(i).dest, adj[cNode].at(i).isSuper, adj[cNode].at(i).percent);//düzgün equation
//        cout << "amount required for child node " << adj[cNode].at(i).dest << " is: " << amountForChild << endl;
        amount = max(amount, amountForChild);
    }

    if(isSuper){
//        cout << "max amount required with super pipe for node " << cNode << " is: " << sqrt(amount)*100/percent << endl;
        return sqrt(amount)*100/percent;
    }
    else{
//        cout << "max amount required for node " << cNode << " is: " << amount << endl;
        return amount*100/percent;
    }

}

int main(){
    int n;
    cin >> n;
    adj.resize(n+5);
    need.resize(n+5);
    int from, to;
    bool isSuper;
     double percent;
    for(int i = 0; i < n-1; i++){
        cin >> from >> to >> percent >> isSuper;
        addEdge(from-1, to-1, percent, isSuper);
    }
    int temp;
    for(int i = 0; i < n; i++){
        cin >> temp;
        need[i] = temp;
    }
    //cout << requiredWater(0, 0, 100) << endl << endl << endl;
    printf("%.9f", requiredWater(0, 0, 100) );
}
