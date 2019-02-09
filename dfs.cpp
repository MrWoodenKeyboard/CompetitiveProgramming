#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void addEdge(vector <int> adj[], int a, int b){
    adj[a].push_back(b);
    adj[b].push_back(a);
}

bool connected(vector <int> adj[], int V){
    bool visited[V];
    for(int i = 0; i < V; i++){
        visited[i] = 0;
    }
    stack <int> s;
    s.push(0);
    visited[0] = 1;
    while(!s.empty()){
        int currentNode = s.top();
//        cout << currentNode << endl;
        s.pop();
        for(int i = 0; i < adj[currentNode].size(); i++){
            if( visited[ adj[currentNode].at(i) ] == 0 ){
                s.push(adj[currentNode].at(i));
                visited[ adj[currentNode].at(i) ] = 1;
            }
        }
    }
    for(int i = 0; i < V; i++){
        if(visited[i] == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector <int> adj[n];
    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        addEdge(adj, a-1, b-1);
    }
    if(connected(adj, n)){
        cout << "Connected";
    }
    else{
        cout << "Not Connected";
    }
}
