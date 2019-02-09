#include <iostream>
#include <vector>
using namespace std;

#define int_max 2147483100

typedef struct edge edge;

struct edge{
    int startNode;
    int endNode;
    int weight;
};

void printArr(int *arr, int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printEdges(vector <edge> edges){
    for(int i = 0; i < edges.size(); i++){
        cout << edges.at(i).startNode << " " << edges.at(i).endNode << " " << edges.at(i).weight << endl;
    }
    cout << endl;
}

void addEdge(int startN, int endN, int weight, vector <edge> *edges){
    edge temp1;
    temp1.startNode = startN;
    temp1.endNode = endN;
    temp1.weight = weight;
//    cout << temp.startNode << " " << temp.endNode << " " << temp.weight << endl;
    (*edges).push_back(temp1);
    edge temp2;
    temp2.startNode = endN;
    temp2.endNode = startN;
    temp2.weight = weight;
//    cout << temp.startNode << " " << temp.endNode << " " << temp.weight << endl;
    (*edges).push_back(temp2);
}

void bellmanFord(vector <edge> edges, int vertexNo, int distances[], int x){
    for(int i = 0; i < vertexNo; i++){
        distances[i] = int_max;
    }
    distances[x] = 0;
    printArr(distances, vertexNo);
    for(int i = 0; i < vertexNo-1; i++){
        cout << i << " edges long" << endl;
        for(int j = 0; j < edges.size(); j++){
            int tempWeight = distances[edges.at(j).endNode] + edges.at(j).weight;
            cout << "Start node: " << edges.at(j).startNode << " End Node: " << edges.at(j).endNode << " Weight: " << edges.at(j).weight << endl;
            cout << "TempWeight: " << tempWeight << endl;
            if(distances[edges.at(j).startNode] > tempWeight){
                distances[edges.at(j).startNode] = distances[edges.at(j).endNode] + edges.at(j).weight;
            }
            else if(distances[edges.at(j).endNode] > tempWeight){
                distances[edges.at(j).endNode] = distances[edges.at(j).startNode] + edges.at(j).weight;
            }
            cout << "Distances:   ";
            printArr(distances, vertexNo);
        }
    }
}

int main(){
    int vertexNo = 5;
    int distances[vertexNo];
    vector <edge> edges;
    addEdge(1,2,5, &edges);
    addEdge(1,0,3, &edges);
    addEdge(0,4,2, &edges);
    addEdge(0,3,1, &edges);
    addEdge(2,4,2, &edges);
    printEdges(edges);
    bellmanFord(edges, vertexNo, distances, 0);
    printArr(distances, vertexNo);
}
