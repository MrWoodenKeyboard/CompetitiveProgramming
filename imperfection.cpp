#include <iostream>
#include <vector>

using namespace std;

#define ll long long

vector <ll> arr;

int main(){
    int a, b;
    cin >> a >> b;
    arr.resize(b+1);
    for(int i = 0; i <= b; i++){
        arr[i] = 0;
    }
    for(int i = 1; i <= b; i++){
        for(int j = i*2; j <= b; j += i){
                cout << "at index: " << j << " adding value: " << i << endl;
            arr[j] += i;
        }
    }
    ll sum = 0;
    for(int i = a; i <=b; i++){
        sum += abs(i - arr[i]);
    }
    cout << sum;
}
