#include <iostream>
#include <vector>

using namespace std;

void printVector(vector <int> v){
    for(int i = 0; i < v.size(); i++){
        cout << v.at(i) << "\t";
    }
    cout << "\n";
}

vector <int> primeFactors(int n){
    vector <int> factors;
    while(n%2 == 0){
        factors.push_back(2);
        n = n/2;
    }
    for(int i = 3; i*i <= n; i += 2){
        while(n%i == 0){
            factors.push_back(i);
            n = n/i;
        }
    }
    if(n > 2){
        factors.push_back(n);
    }
    return factors;
}

int sumOfDigits(int n){
    int sum = 0;
    while(n > 0){
        sum += n%10;
        n /= 10;
    }
    return sum;
}

int main(){
    int n;
    cin >> n;
    vector <int> factors = primeFactors(n);
    int sumOfDigit = sumOfDigits(n);
    int sumOfPrimes = 0;
    for(int i = 0; i < factors.size(); i++){
        sumOfPrimes += sumOfDigits(factors.at(i));
    }
    if(sumOfDigit == sumOfPrimes){
        cout << "1" << endl;
    }
    else{
        cout << "0" << endl;
    }
}
