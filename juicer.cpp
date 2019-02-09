#include <iostream>

using namespace std;

int main(){
    int n, b, d, waste = 0, collect = 0;
    cin >> n >> b >> d;
    int oranges[n];
    for(int i = 0; i < n; i++){
        cin >> oranges[i];
    }
    for(int i = 0; i < n; i++){
        if(oranges[i] <= b){
            waste += oranges[i];
        }
        if(waste > d){
            waste = 0;
            collect++;
        }
    }
    cout << collect;
}
