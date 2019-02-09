#include <iostream>

using namespace std;

int main(){
    int t, length, temp, ans = 0;
    cin >> t >> length;
    for(int i = 0; i < t; i++){
        cin >> temp;
        if(temp > length){
            ans = ans + 2;
        }
        else{
            ans = ans + 1;
        }
    }
    cout << ans;
}
