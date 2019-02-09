#include <iostream>

using namespace std;

int main(){
    int n, x, a;
    cin >> n >> x >> a;
    int b;
    if(n == 1){
        b = 0;
    }
    else{
        b = ( (n * a) - x ) / (n - 1)  ;
    }
    cout << b;
}
