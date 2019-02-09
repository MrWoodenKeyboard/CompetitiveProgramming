#include <iostream>
#include <string>
using namespace std;

string toLowerCase(string word){
    string temp;
    for(int i = 0; i < word.length(); i++){
        if(word.at(i) > 64 && word.at(i) < 91){
            temp = word.at(i) + 32;
            word.replace(i, 1, temp);
        }
    }
    return word;
}

int main(){
    int n;
    cin >> n;
    string word;
    cin >> word;
    word = toLowerCase(word);
    int alphabet[26], temp;
    for(int i = 0; i < word.length(); i++){
        temp = word.at(i) - 97;
        alphabet[temp] = 1;
    }
    for(int i = 0; i < 26; i++){
        if(alphabet[i] != 1){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}
