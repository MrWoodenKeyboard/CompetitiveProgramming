#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<vector<int> > graph;
//vector<int> parent;
vector<int> key;
vector<bool> mst;

int minKey(){
    int min = INT_MAX, minIndex;
    for(int i = 0; i < key.size(); i++){
        if(mst[i] == false && key[i] < min){
            min = key[i];
            minIndex = i;
        }
    }
    return minIndex;
}

int primMST(){
    int totalWeight = 0;
    key[0] = 0;
    int current;
    for(int i = 0; i < graph.size(); i++){
        current = minKey();
        mst[current] = true;

        totalWeight += key[current];

        for(int j = 0; j < graph.size(); j++){
            if(graph[current][j] != INT_MAX && mst[j] == false && graph[current][j] < key[j]){
                 key[j] = graph[current][j];
            }
        }
    }
    return totalWeight;
}


int main(){
    int n, m;
    cin >> n >> m;
    graph.resize(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            graph[i][j] = INT_MAX;
        }
    }

    //parent.assign(n, -1);
    key.assign(n, INT_MAX);
    mst.assign(n, false);
    //birden fazla edge olabileceði için kontrol et
    int a, b, w;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> w;
        a--, b--;
        if( graph[a][b] > w ){
            graph[a][b] = w;
            graph[b][a] = w;
        }
    }
//    cout << "wqe" << endl;
    int start;
    cin >> start;
    cout << primMST();
}
