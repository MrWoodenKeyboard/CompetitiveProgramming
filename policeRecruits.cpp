#include <iostream>

using namespace std;

int main(){
    int n, police = 0, temp, cases = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        police = police + temp;
        if(police < 0){
            cases = cases + police*-1;
            police = 0;
        }
    }
    cout << cases;
}
