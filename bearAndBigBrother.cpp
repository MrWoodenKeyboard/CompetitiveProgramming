#include <iostream>

using namespace std;

int main(){
    int small, big, year = 0;
    cin >> small >> big;
    while(small <= big){
        small = small*3;
        big = big*2;
        year++;
    }
    cout << year;
}
