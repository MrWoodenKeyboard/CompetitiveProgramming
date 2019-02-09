#include <iostream>

using namespace std;

void printArr(long long *arr, long long len){
    for(int i = 0; i < len; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    long long n, sum;
    cin >> n >> sum;
    long long arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    long long ans = 0;
    long long currentSum = 0;
    long long first = 0;
    for(int i = 0; i < n; i++){
        currentSum += arr[i];

        while(currentSum > sum){
            currentSum -= arr[first];
            first++;
        }

        if(currentSum == sum){
            ans++;
        }
    }
//    printArr(sums, n);
    cout << ans;
}
