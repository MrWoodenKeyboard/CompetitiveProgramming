#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int friends[n];
    for(int i = 0; i < n; i++){
        cin >> friends[i];
    }
    int index, i;
    for(index = 1; index <= n; index++){
        for(i = 0; friends[i] != index; i++){}
        cout << i + 1 << " ";
    }
}
