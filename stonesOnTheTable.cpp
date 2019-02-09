#include <iostream>
#include <string>
using namespace std;

int main(){
    int n, temp, moves = 0;
    cin >> n;
    string stones;
    cin >> stones;
    temp = stones.at(0);
    for(int i = 1; i < n; i++){
        if(temp == stones.at(i)){
            moves++;
        }
        temp = stones.at(i);
    }
    cout << moves;
}
