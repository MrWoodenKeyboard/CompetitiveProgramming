#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > adj;

void addEdge(int from, int to){
    adj[from].push_back(to);
}

int findLength(int n){
//    cout << "inside with: " << n << endl;
    if(adj[n].empty()){
//        cout << "returning: 1" << endl;
        return 1;
    }
    int ans = findLength(adj[n][0]);
    for(int i = 1; i < adj[n].size(); i++ ){
//        cout << "comparing: " << ans << " and the level of " << adj[n][i] << endl;
        ans = max ( ans, findLength(adj[n][i]) );
    }
//    cout << "returning: " << ans+1 << endl;
    return ans+1;
}


int main(){
    int n;
    cin >> n;
    adj.resize(n+2);
    int a, b;
    for(int i = 0; i < n-1; i++){
        cin >> a >> b;
        addEdge(b, a);
    }
//    cout << "done inputting" << endl;
    cout << findLength(1);
}
