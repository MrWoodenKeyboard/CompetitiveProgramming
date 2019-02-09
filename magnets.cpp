#include <iostream>

using namespace std;

int main(){
    int n, group = 1, current, prev;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> current;
        if(i != 0){
            if(prev != current){
                group++;
            }
        }
        prev = current;
    }
    cout << group;
}
