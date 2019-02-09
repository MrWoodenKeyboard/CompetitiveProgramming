#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n){
    if(n <= 1){
        return false;
    }
    for(int i = 2; i <= sqrt(n); i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

void printPrimesBetween(int first, int last){
    for(int i = first; i <= last; i++){
        if(isPrime(i) == true){
            cout << i << endl;
        }
    }
}

int main(){
    int t, first, last;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> first;
        cin >> last;
        printPrimesBetween(first, last);
        cout << endl;
    }
}
