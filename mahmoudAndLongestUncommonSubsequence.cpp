#include <iostream>
#include <string>
using namespace std;

int main(){
    string first, second;
    cin >> first >> second;
    if(first.length() != second.length()){
        cout << max(first.length(), second.length());
        return 0;
    }
    for(int i = 0; i < first.length(); i++){
        if(first.at(i) != second.at(i)){
            cout << first.length();
            return 0;
        }
    }
    cout << "-1";
}
