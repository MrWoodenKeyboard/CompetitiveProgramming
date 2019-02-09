#include <iostream>
#include <vector>

using namespace std;

vector <long long> piles;

long long divide(long long dividend, long long divisor){
    long long quotient = dividend/divisor;
    if(dividend%divisor == 0){
        return quotient;
    }
    else{
        return quotient + 1;
    }
}

bool enough(long long uppLim, long long h, long long n){
    long long reqH = 0;
    for(int i = 1; i <= n; i++){
        reqH += divide(piles[i], uppLim);
    }
    if(reqH <= h){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    long long n, h;
    cin >> n >> h;
    piles.resize(n+4);
    for(int i = 1; i <= n; i++){
        cin >> piles[i];
    }
    long long uppLim = 922337203685477580;//sonunu 6 yaparsin en olmadi
    long long lowLim = 1;
    long long reqH = 0;
    while(uppLim - lowLim > 1){
        long long mid = (uppLim + lowLim)/2;
        for(int i = 1; i <= n; i++){
            reqH += divide(piles[i], mid);
        }
        if(reqH <= h){
            uppLim = mid;
        }
        else{
            lowLim = mid;
        }
        reqH = 0;
//        cout << "lowLim: " << lowLim << "  uppLim: " << uppLim << endl;
    }
    if(enough(lowLim, h, n)){
        cout << lowLim;
    }
    else{
        cout << uppLim;
    }
}
