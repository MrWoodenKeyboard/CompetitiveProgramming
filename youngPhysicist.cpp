#include <iostream>

using namespace std;

int main(){
    int n, x = 0, y = 0, z = 0, temp;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        x += temp;
        cin >> temp;
        y += temp;
        cin >> temp;
        z += temp;
    }
    if(x == 0 && y == 0 && z == 0){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}
