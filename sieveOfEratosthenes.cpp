#include <iostream>
#include <cmath>
using namespace std;

void sieveOfEratosthenes(int n){
    int prime[n+1];
    for(int i = 0; i < n + 1; i++){
        prime[i] = 1;
    }
    prime[0] = 0;
    prime[1] = 0;
    for(int i = 2; i < n+1; i++){
        if(prime[i] == 1){
            cout << i << endl;
            for(int j = i*2; j < n+1; j = j + i){
                prime[j] = 0;
            }
        }
    }
}

int main(){
    sieveOfEratosthenes(100);
}
