#include <iostream>

using namespace std;

typedef struct team team;

struct team{
    int home;
    int away;
};

int main(){
    int n, ans = 0;
    cin >> n;
    team teams[n];
    for(int i = 0; i < n; i++){
        cin >> teams[i].home;
        cin >> teams[i].away;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(teams[i].home == teams[j].away){
                ans++;
            }
        }
    }
    cout << ans;
}
