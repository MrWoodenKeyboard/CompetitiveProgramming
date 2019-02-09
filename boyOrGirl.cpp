#include <iostream>
#include <string>
using namespace std;

int main(){
    string name;
    cin >> name;
    int distinct = 1, sameness = 0;
    for(int i = 1; i < name.length(); i++){
        for(int j = i - 1; j >= 0; j--){
//            cout << "i: " << i << "   j; " << j << endl;
            if(name.at(i) == name.at(j)){
                sameness = 1;
            }
        }
        if(sameness == 1){
            sameness = 0;
            continue;
        }
        distinct++;
    }
    if(distinct%2 == 0){
        cout << "CHAT WITH HER!";
    }
    if(distinct%2 == 1){
        cout << "IGNORE HIM!";
    }
}
