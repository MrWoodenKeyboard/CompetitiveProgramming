#include <iostream>
#include <string>
using namespace std;

void lexicographicComparison(string first, string second){
    int firstVal, secondVal;
    for(int i = 0; i < first.length(); i++){
        if(first.at(i) > 'Z'){
            firstVal = (int)first.at(i) - 32;
        }
        else{
            firstVal = (int)first.at(i);
        }
        if(second.at(i) > 'Z'){
            secondVal = (int)second.at(i) - 32;
        }
        else{
            secondVal = (int)second.at(i);
        }
        if(firstVal > secondVal){
            cout << 1;
            return;
        }
        if(firstVal < secondVal){
            cout << -1;
            return;
        }
    }
    cout << 0;
    return;
}

int main(){
    string str1, str2;
    cin >> str1 >> str2;
    lexicographicComparison(str1, str2);
}
