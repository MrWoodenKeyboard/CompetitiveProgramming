#include <iostream>

using namespace std;


int arr[100005];
int dp[100005];
int main(){
    for(int i = 0; i < 100005; i++){
        arr[i] = 0;
        dp[i] = 0;
    }
    int n;
    cin >> n;
    int temp;
    for(int i = 0; i < n; i++){
        scanf("%d", &temp);
        arr[temp]++;
    }
    dp[1] = arr[1];
    for(int i = 2; i <= 100001; i++){
        dp[i] = max( dp[i-1], dp[i-2] + arr[i] * i );
    }
    cout << dp[100000];
}
