#include <iostream>
#include <cmath>

using namespace std;

bool isPerfectSquare(int n){
    int s = sqrt(n);
    if(s*s == n){
        return true;
    }
    return false;
}

bool isFibonacci(int n){
    if( isPerfectSquare(5*n*n + 4) || isPerfectSquare(5*n*n - 4) ){
        return true;
    }
    return false;
}

bool isPrime(int n){
    for(int i = 2; i*i <= n; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

bool isCube(int n){

}

int main(){
    int t, n;
    cin >> t >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int type, number;
    for(int i = 0; i < t; i++){
        cin >> type >> number;
    }
}
