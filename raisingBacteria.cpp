#include <iostream>
#include <cmath>
using namespace std;
//WRONG CODE FUCK ME
int main(){
    long long n;
    cin >> n;
    long long i;
    for(i = 1; i*2 <= n; i *= 2){}
    cout << n - i + 1;
}
