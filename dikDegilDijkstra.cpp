#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <vector<int> > adj;

void addEdge(int from, int to){
    adj[from].push_back(to);
}

void shortestPath(int from, int to){
//    cout << "in shortesPath\n";
    queue <int> nodes;
    queue <int> distances;
    bool visited[adj.size()];
    for(int i = 0; i < adj.size(); i++){
        visited[i] = 0;
    }
//    cout << "initialized visited array\n";
    nodes.push(from);
    distances.push(0);
    while(!nodes.empty()){
        int cNode = nodes.front();
        nodes.pop();
        int cDistance = distances.front();
        distances.pop();
//        cout << "looking at node: " << cNode << " and the distance is: " << cDistance << endl;
        if(cNode == to){
            cout << cDistance;
            return;
        }
        for(int i = 0; i < adj[cNode].size(); i++){
            if( !visited[ adj[cNode].at(i) ] ){
                nodes.push(adj[cNode].at(i));
                distances.push(cDistance+1);
            }
        }
        visited[cNode] = 1;
    }
    cout << "No Path!";
}

int main(){
    int t;
    cin >> t;
    int n, m, a, b;
    for(int i = 0; i < t; i++){
        cin >> n >> m >> a >> b;
//        cout << "the first 4 parameters are taken\n";
        adj.clear();
        adj.resize(n);
        int from, to;
        for(int j = 0; j < m; j++){
            cin >> from >> to;
            addEdge(from-1, to-1);
        }
//        cout << "edges are taken\n";
        shortestPath(a-1, b-1);
        if(i != t-1){
            cout << endl << "--" << endl;
        }
    }

}
