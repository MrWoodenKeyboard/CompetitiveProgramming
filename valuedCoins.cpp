#include <iostream>
#include <vector>

using namespace std;

vector <int> coins;

bool findSum(int m, int n){
//    cout << "inside with: " << m << " and " << n << endl;
    if(n == 0){
        return true;
    }
    if(n < 0){
        return false;
    }
    if(m <= 0 && n > 0){
        return false;
    }

    return findSum(m-1, n) || findSum(m-1, n - coins[m-1]);
}

int main(){
    int m, n;
    cin >> m >> n;
    coins.resize(m);
    for(int i = 0; i < m; i++){
        cin >> coins[i];
    }
    if(findSum(m, n)){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}
