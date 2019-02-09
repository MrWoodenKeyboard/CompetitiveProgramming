#include <iostream>

using namespace std;

int main(){
    long long l, r;
    cin >> l >> r;
    long long difference = r - l;

    if(difference < 2){
        cout << "-1";
        return 0;
    }
    if(l%2 == 0){
        cout << l << " " << l+1 << " " << l+2;
        return 0;
    }
    else if(difference > 2 && l%2 == 1){
        cout << l+1 << " " << l+2 << " " << l+3;
        return 0;
    }

    cout << "-1";
}
