#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long fastExp(long long base, long long power){
    if(power == 1){
        return base;
    }
//    cout << base << "  " << power << endl;


    if(power%2 == 0){
        return fastExp(base*base, power/2);
    }
    else{
        return fastExp(base*base, power/2)*base;
    }

}


int main() {
    long long n;
    cin >> n;
    long long ans = 0;
    for(long long i = n; i > 0; i--){
        ans = ans + fastExp(2, i);
    }
    cout << ans;
    return 0;
}
