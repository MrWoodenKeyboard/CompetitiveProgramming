#include <iostream>
#include <queue>

using namespace std;

vector <vector<int> > adj;
vector <int> colors;
queue<int> q;

void printVector(vector<int> v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

bool isBipartiteUtil(int node){
    q.pop();
    int color;
    if( colors[node] == 1 ){
        color = 2;
    }
    else{
        color = 1;
    }

    for(int i = 0; i < adj[node].size(); i++){
        q.push( adj[node][i] );
        if( colors[ adj[node][i] ] == 0 || colors[ adj[node][i] ] == color ){
            colors[ adj[node][i] ] = color;
        }
        else{
            return false;
        }
    }

    if(q.empty()){
        return true;
    }

    return isBipartiteUtil(q.front());
}



bool isBipartite(int n){

    //making sure that the global variables are cleared and ready to use
    while(!q.empty()){
        q.pop();
    }

    colors.assign(n, 0);//0 is colorless, 1 and 2 are distinct colors

    cout << "colors is cleared " << endl;
    printVector(colors);

    int root = 0;//arbirary root
    colors[root] = 1;//arbitrary first color assignation

    q.push(root);

    return isBipartiteUtil(root);
}

void addEdge(int from, int to){
    adj[from].push_back(to);
}

int main(){
    int n = 5;
    adj.resize(n);
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 4);
    addEdge(2, 3);
    cout << isBipartite(n);
    cout << "colors vector after first check:" << endl;
    printVector(colors);

    addEdge(1, 3);
    cout << isBipartite(n);
    cout << "colors vector after second check:" << endl;
    printVector(colors);

    addEdge(1, 2);
    cout << isBipartite(n);
    cout << "colors vector after third check:" << endl;
    printVector(colors);
}
