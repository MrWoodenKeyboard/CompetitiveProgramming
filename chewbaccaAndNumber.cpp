#include <iostream>
#include <string>
using namespace std;

string findSmallest(string number){
    for(int i = 0; i < number.length(); i++){
        if(number.at(i) >= '5' && !(i == 0 && number.at(i) == '9') ){
            char temp = '9' - number.at(i) + '0';
            number.at(i) = temp;
//            number.replace(i, 1, temp);
        }
    }
    return number;
}

string checkZero(string number){
    while(number.at(0) == '0' && number.length() > 1){
//        cout << number << endl;
        number.erase(0, 1);
    }
    return number;
}

int main(){
    string number;
    cin >> number;
    number = findSmallest(number);
    number = checkZero(number);
    cout << number;
}
