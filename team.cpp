#include <iostream>

using namespace std;

int main(){
    int n, first, second, third, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> first >> second >> third;
        if(first + second + third >= 2){
            ans++;
        }
    }
    cout << ans;
}
