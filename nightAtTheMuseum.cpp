#include <iostream>
#include <string>
using namespace std;

int main(){
    string word;
    cin >> word;
    int currentValue = 0, nextValue, rotation = 0;
    for(int i = 0; i < word.length(); i++){
        nextValue = word.at(i) - 97;
        if(26 - abs(nextValue - currentValue) < abs(nextValue - currentValue)){
            rotation = rotation + 26 - abs(nextValue - currentValue);
        }
        else{
            rotation = rotation + abs(nextValue - currentValue);
        }
        currentValue = nextValue;
    }
    cout << rotation;
}
