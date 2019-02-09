#include <iostream>
#include <string>
using namespace std;

string toLowerCase(string word){
    string temp;
    for(int i = 0; i < word.length(); i++){
        if(word.at(i) < 91 && word.at(i) > 64){
            temp = word.at(i) + 32;
//            cout << "i: " << i << endl;
//            cout << temp;
            word.replace(i, 1, temp);
        }
    }
    return word;
}

int main(){
    string word;
    cin >> word;
    word = toLowerCase(word);
//    cout << "dafux";
//    cout << word.length() << endl;
    for(int i = 0; i < word.length(); i++){
//            cout << i << "  " << word.length() << "  " << word << endl;
        if(word.at(i) == 'a' || word.at(i) == 'o' || word.at(i) == 'y' || word.at(i) == 'e' || word.at(i) == 'u' || word.at(i) == 'i'){
            word.erase(i, 1);
            i--;
        }
        else{
            word.insert(i, ".");
            i++;
        }
    }
    cout << word;
}


