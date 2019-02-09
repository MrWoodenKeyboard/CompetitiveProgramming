#include <iostream>
#include <string>
using namespace std;

int main(){
    string word;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> word;
        if(word.length() <= 10){
            cout << word << endl;
        }
        else{
        cout << word.at(0) << word.length() - 2 << word.at(word.length() - 1) << endl;
        }
    }
}
