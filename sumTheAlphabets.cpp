#include <iostream>
#include <string>
using namespace std;

int sum(string str){
    int sum = 0;
    for(int i = 0; i < str.length(); i++){
        sum += (str.at(i) - 'a')%5;
    }
    return sum;
}

int main(){
    int n;
    cin >> n;
    string str;
    for(int i = 0; i < n; i++){
        cin >> str;
        cout << sum(str) << endl;
    }
}
