#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }
    cout << endl;
}

int* dfs(vector<int> adj[], int n){
    int* arr = new int[n+1];
    for(int i = 0; i < n+1; i++){
        arr[i] = 0;
    }
    //printArr(arr, n+1);
    stack <int> s;
    arr[1] = 1;
    for(int i = 0; i < adj[1].size(); i++){
        s.push(adj[1].at(i));
    }
    while(!s.empty()){
        //printArr(arr, n+1);
        for(int i = 0; i < adj[s.top()].size(); i++){
            if(arr[adj[s.top()].at(i)] == 0){
                s.push(adj[s.top()].at(i));
            }
        }
        arr[s.top()] = 1;
        s.pop();
    }
    return arr;
}

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> adj[n+1];

    int from, to;
    for(int i = 0; i < m; i++){
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    //int *arr = (int*) malloc(sizeof(int)*n);
    int *arr = dfs(adj, n);
    //cout << "returned" << endl;
    for(int i = 1; i < n+1; i++){
        //cout << "why do you take too long?" << endl;
        if(*(arr+i) == 0){
            cout << "Not Connected";
            return 0;
        }
    }
    cout << "Connected";
}
