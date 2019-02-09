#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int> > m;
int n;


int opened(int a, int b){
    cout << "n is " << n << endl;
    cout << "in with " << a << "  " << b << endl;
    if(b == n){
        cout << "asd" << endl;
    }

    if( (m[a][b] == 0) || (a < 0) || (b < 0) || (a == n) || (b == n) ){
        cout << "returning 0" << endl;
        return 0;
    }
    else{
        m[a][b] = 0;
        return 1 + opened(a+1, b) + opened(a-1, b) + opened(a, b+1) + opened(a, b-1);
    }
}

int main() {
    cin >> n;
    m.resize(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> m[i][j];
        }
    }

    int a, b;
    cin >> a >> b;
/*
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
*/
    cout << opened(a, b);
    cout << "end";
    return 0;
}
