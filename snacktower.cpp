#include <iostream>

using namespace std;

int main(){
    int n, temp, index;
    cin >> n;
    index = n-1;
    int snacks[n];
    for(int i = 0; i < n; i++){
        snacks[i] = 0;
    }
    for(int i = 0; i < n; i++){
        cin >> temp;
        snacks[temp - 1] = 1;
        while(snacks[index] == 1){
            cout << index + 1 << " ";
            index--;
            if(index == -1){
                return 0;
            }
        }

        cout << endl;
    }
}
