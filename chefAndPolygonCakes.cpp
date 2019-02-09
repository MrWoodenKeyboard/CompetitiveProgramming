#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int gcd(int a, int b){
    int gcd, r;
     if(a==0 || b==0)
             return gcd =  1;
    else{
        r = (a%b);
        while ( r < 0 || r > 0){
                a = b;
                b = r;
                r = (a%b);
        }
        gcd = b;
    }
         return gcd;
}

void printKth(int n, int first, int k){
    int total = 180*(n-2);
    int numeratorNth = 2*total - n*first;
    int gcdNth = gcd(numeratorNth, n);
    numeratorNth = numeratorNth/gcdNth;
    int denominatorNth = n/gcdNth;
    int numeratorIncrement = numeratorNth - first * denominatorNth;
    int denominatorIncrement = denominatorNth*(n-1);
    int gcdIncrement = gcd(numeratorIncrement, denominatorIncrement);
    numeratorIncrement = numeratorIncrement/gcdIncrement;
    denominatorIncrement = denominatorIncrement/gcdIncrement;
    int numeratorKth = first*denominatorIncrement + (k-1)*numeratorIncrement;
    int denominatorKth = denominatorIncrement;
    int gcdKth = gcd(numeratorKth, denominatorKth);
    cout << numeratorKth/gcdKth << " " << denominatorKth/gcdKth << "\n";
}

int main(){
    int t, n, a, k;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n >> a >> k;
        printKth(n, a, k);
    }
}
