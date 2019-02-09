#include <iostream>

using namespace std;

int utopianTree(int n){
    int l = 1;
    for(int i = 1; i <= n; i++){
        if(i%2 == 0){
            l++;
        }
        else{
            l *= 2;
        }
    }
    return l;
}


int main(){
    int t, n;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        cout << utopianTree(n) << endl;
    }
}
