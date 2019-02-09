#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct edge edge;
typedef struct graph graph;

struct edge{
    int src, dest, w;

    bool operator < (const edge& e) const
    {
        return (w < e.w);
    }
};

struct graph{
    int e, v;
    vector<edge> edges;
};

vector<int> sets;
vector<int> ranks;
graph g;

int parent(int n){
    if(sets[n] == n){
        return n;
    }
    return parent(sets[n]);
}

void unionSets(int a, int b){
//    cout << "inside union" << endl;
    int pa = parent(a);
    int pb = parent(b);
    if(ranks[pb] < ranks[pa]){
        sets[pb] = pa;
        ranks[pb] += ranks[pa];
    }
    else{
        sets[pa] = pb;
        ranks[pa] += ranks[pb];
    }
//    cout << "finished union" << endl;
}

int kruskal(){
    sort(g.edges.begin(), g.edges.end());
    int totalW = 0;
    int e = 0;//total edges chosen
    int i = 0;//iterator for edges
    edge currentE;
    while(e < g.v - 1){
//        cout << "e: " << e << "  i: " << i << endl;
        currentE = g.edges[i];
        i++;
        int x = parent(currentE.src);
        int y = parent(currentE.dest);
        if(x != y){
//            cout << "no cycle" << endl;
            totalW += currentE.w;
            e++;
            unionSets(x, y);
        }
    }
//    cout << "finished loop" << endl;
    return totalW;
}

int main(){
    int v, e;
    cin >> v >> e;
    sets.resize(v);
    for(int i = 0; i < v; i++){
        sets[i] = i;
    }
    ranks.assign(v, 1);
    g.e = e; g.v = v;
    int a, b, w;
    edge temp;
    for(int i = 0; i < e; i++){
        cin >> a >> b >> w;
        temp.src = a-1;
        temp.dest = b-1;
        temp.w = w;
        g.edges.push_back(temp);
    }
//    cout << "going into the function" << endl;
    cout << kruskal();
}
