#include <iostream>

using namespace std;


int main(){
    int n, m;
    cin >> n >> m;
    int win[m][n];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> win[i][j];
        }
    }
    int dp[m][n];
    for(int i = 0; i < m; i++){
        dp[i][0] = win[i][0];
    }
    int minV;
    for(int i = 1; i < n; i++){
        minV = dp[0][i-1] + win[0][i];
        for(int j = 0; j < m; j++){
            minV = min(minV, dp[j][i-1]);
            dp[j][i] = minV + win[j][i];
        }
    }
    minV = dp[0][n-1];
    for(int i = 0; i < m; i++){
        minV = min(dp[i][n-1], minV);
    }

/*
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << win[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
*/

    cout << minV;
}
