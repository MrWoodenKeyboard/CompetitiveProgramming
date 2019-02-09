#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int> > dp;
stack<int> s;

int LCS(int arr1[], int arr2[], int i1, int i2){
//    cout << "inside with " << i1 << " and " << i2 << endl;
    if(i1 == -1 || i2 == -1){
        return 0;
    }
    if(dp[i1][i2] != -1){
        return dp[i1][i2];
    }
    if(arr1[i1] == arr2[i2]){
        return dp[i1][i2] = 1 + LCS(arr1, arr2, i1-1, i2-1);
    }
    else{
        return dp[i1][i2] = max( LCS(arr1, arr2, i1-1, i2), LCS(arr1, arr2, i1, i2-1) );
    }
}

void printLCS(int i1, int i2, int arr1[], int arr2[]){
//    cout << endl << "entered printLCS with " << i1 << " and " << i2 << endl;
    if(i1 == 0 ){
        if(arr1[i1] != arr2[i2]){
            return printLCS(i1, i2-1, arr1, arr2);
        }
        else{
            s.push( arr1[i1] );
            return;
        }

    }
    if(i2 == 0){
        if(arr1[i1] != arr2[i2]){
            return printLCS(i1-1, i2, arr1, arr2);
        }
        else{
            s.push( arr1[i1] );
            return;
        }
    }


    if( dp[i1][i2] > max( dp[i1-1][i2], dp[i1][i2-1] ) ){
//        cout << endl << "the max!" << endl;
        s.push( arr1[i1] );
        return printLCS(i1-1, i2-1, arr1, arr2);
    }
    else{
//        cout << endl << "not the max!" << endl;
        if(dp[i1-1][i2] > dp[i1][i2-1]){

            return printLCS(i1-1, i2, arr1, arr2);
        }
        else{

            return printLCS(i1, i2-1, arr1, arr2);
        }
    }
}


int main(){
    int a, b;
    cin >> a >> b;
    int arr1[a], arr2[b];
    for(int i = 0; i < a; i++){
        cin >> arr1[i];
    }
    for(int i = 0; i < b; i++){
        cin >> arr2[i];
    }
    dp.resize(a, vector<int>(b));
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            dp[i][j] = -1;
        }
    }
    int z = LCS(arr1, arr2, a-1, b-1);

/*
    cout << endl;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            cout << dp[i][j] << "       ";
        }
        cout << endl;
    }
    cout << endl;
*/

    printLCS(a-1, b-1, arr1, arr2);
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
}
