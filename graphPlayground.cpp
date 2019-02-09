#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

void printVector(vector <int> v){
    for(int i = 0; i < v.size(); i++){
        cout << v.at(i) << " ";
    }
    cout << endl;
}

void printStack(stack <int> s){
    stack <int> temp = s;
    while(!temp.empty()){
        cout << temp.top();
        temp.pop();
    }
    cout << endl;
}

void addEdge(vector <int> adj[], int first, int second){
    adj[first].push_back(second);
    adj[second].push_back(first);
}

void printGraph(vector <int> adj[], int n){
    for(int i = 0; i < n; i++){
        printVector(adj[i]);
    }
}

bool contains(int n, vector <int> v){
    for(int i = 0; i < v.size(); i++){
        if(v.at(i) == n){
            return true;
        }
    }
    return false;
}

void DFT(vector <int> adj[], int n){
    stack<int> s;
    vector <int> visited;
    int temp;
    s.push(0);
    while(!s.empty()){
        if(contains(s.top(), visited)){
            s.pop();
        }
        else{
            temp = s.top();
            s.pop();
            visited.push_back(temp);
            for(int i = 0; i < adj[temp].size(); i++){
                s.push(adj[temp].at(i));
            }
            cout << temp << endl;
//            cout << "Stack is:  ";
//            printStack(s);
        }
    }
    cout << endl;
}

void BFT(vector <int> adj[], int n){
    queue<int> q;
    vector<int> visited;
    q.push(0);
    while(!q.empty()){
        if(contains(q.front(), visited)){
            q.pop();
        }
        else{
            for(int i = 0; i < adj[q.front()].size(); i++){
                q.push(adj[q.front()].at(i));
            }
            cout << q.front() << endl;
            visited.push_back(q.front());
            q.pop();
        }
    }
    cout << endl;
}

int main(){
    int n = 5;
    vector <int> adj[n];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    DFT(adj, n);
    BFT(adj, n);
}
