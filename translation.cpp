#include <iostream>
#include <string>
using namespace std;

int main(){
    string first, second;
    cin >> first >> second;
    if(first.length() != second.length()){
        cout << "NO";
        return 0;
    }
    for(int i = 0, j = first.length()-1; i < first.length(); i++, j--){
        if(first.at(i) != second.at(j)){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}


