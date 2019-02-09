#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    cin >> str;
    int val = str.at(0);
    string temp;
    if(val > 91){
        val = val - 32;
        temp = val;
        str.replace(0, 1, temp);
    }
    cout << str;
}
