#include <iostream>
#include <cmath>
using namespace std;

void sieveOfEratosthenes(int m, int n){
    int prime[n+1];
    for(int i = 0; i < n + 1; i++){
        prime[i] = 1;
    }
    prime[0] = 0;
    prime[1] = 0;
    for(int i = 2; i < n+1; i++){
        if(prime[i] == 1){
            if(i >= m){
                cout << i << endl;
            }
            for(int j = i*2; j < n+1; j = j + i){
                prime[j] = 0;
            }
        }
    }
}

int main(){
    int t, first, last;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> first;
        cin >> last;
        sieveOfEratosthenes(first, last);
        cout << endl;
    }
}
//time limit exceeded aldý ama harbi inefficent gözüküyor zaten çözdüm trial division ile
