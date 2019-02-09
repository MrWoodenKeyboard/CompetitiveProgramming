#include <iostream>

using namespace std;

int main(){
    int arr[1001];
    for(int i = 0; i <= 1000; i++){
        arr[i] = 0;
    }
    int n, temp;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        arr[temp]++;
    }
    for(int i = 0; i <= 1000; i++){
        if(arr[i] > (n+1)/2){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
