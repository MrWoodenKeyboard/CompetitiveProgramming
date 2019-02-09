#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int> > st;

void printST( vector <vector<int> > st){
    for(int i = 0; i < st.size(); i++){
        for(int j = 0; j < st[0].size(); j++){
            cout << st[i][j] << " ";
        }
        cout << endl;
    }
}

vector <vector<int> > build(int arr[], int len){
    int log = 0;
    for(int i = len; i > 0; i = i/2){
        log++;
    }
    vector <vector<int> > st(log, vector<int>(len));
    for(int i = 0; i < len; i++){
        st[0][i] = arr[i];
    }
    for(int j = 1; j < log; j++){
//        cout << "row "<< j+1 <<":" << endl << endl;
        for(int i = 0; i + pow(2, j-1) <= len - pow(2, j-1) ; i++){
//            cout << "column "<< i+1 <<":" << endl;
//            cout << st[j - 1][ i + pow(2, j-1) ] << "  " << st[j - 1][i] << endl;
            st[j][i] = min( st[j - 1][ i + pow(2, j-1) ], st[j - 1][i] );
        }
    }
    return st;
}

int findMin(int l, int r){
    int i = (int) log2(r-l+1);
    int min1 = st[i][l];
    int min2 = st[i][ r - (1<<i) + 1 ];
    return min(min1, min2);
}

int main(){

    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }


    st = build(arr, n);

    int q;
    cin >> q;
    int i ,j;
    for(int a = 0; a < q; a++){
        cin >> i >> j;
        cout << findMin(i, j) << endl;
    }

}
