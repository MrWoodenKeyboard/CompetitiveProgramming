#include <iostream>

using namespace std;

int multiply(int multiplier, int* answer, int numberSize){
    int carry = 0, product;
    for(int i = 0; i < numberSize; i++){
        product = answer[i] * multiplier + carry;
        answer[i] = product%10;
        carry = product/10;
    }
    while(carry){
        answer[numberSize] = carry%10;
        carry = carry/10;
        numberSize++;
    }
    return numberSize;
}


void factorial(int n){
    int answer[1000];
    answer[0] = 1;
    int numberSize = 1;
    for(int i = 2; i <= n; i++){
        numberSize = multiply(i, answer, numberSize);
    }
    for(int i = numberSize - 1; i >= 0; i--){
        cout << answer[i];
    }
}

int main(){
    int n = 100;
    factorial(n);
    cout << endl;
}
