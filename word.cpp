#include <iostream>
#include <string>
using namespace std;

int main(){
    string word;
    cin >> word;
    int upper = 0, lower = 0;
    int values[word.length()];
    for(int i = 0; i < word.length(); i++){
        values[i] = word.at(i);
        if(values[i] > 94){
            lower++;
        }
        else{
            upper++;
        }
    }
//    cout << upper << "  " << lower << endl;
    if(upper > lower){
        for(int i = 0; i < word.length();i++){
            if(values[i] > 94){
                values[i] = values[i] - 32;
            }
        }
    }
    else{
//      cout << "else";
        for(int i = 0; i < word.length(); i++){
            if(values[i] < 94){
                values[i] = values[i] + 32;
            }
        }
    }
    char temp;
    for(int i = 0; i < word.length(); i++){
        temp = values[i];
        cout << temp;
    }
}
