#include <iostream>
#include <string>
using namespace std;

int main(){
    string stones, instructions;
    cin >> stones >> instructions;
    int current = 0;
    for(int i = 0; i < instructions.length(); i++){
        if(stones.at(current) == instructions.at(i)){
            current++;
        }
    }
    cout << current + 1;
}
