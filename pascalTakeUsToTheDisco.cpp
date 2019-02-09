#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int t, n;
    cin >> t;
    long long ans;
    for(int i = 0; i < t; i++){
        cin >> n;
        ans = fmod( pow(2, n) - 1, (pow(10, 9) + 7) );
        cout << ans << endl;
    }
}
