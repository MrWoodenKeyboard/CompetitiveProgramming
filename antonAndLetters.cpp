#include <iostream>
#include <string>
using namespace std;

int main(){
    string letters;
    int alphabet[26], ans = 0;
    getline(cin, letters);
//    cout << "length is: " << letters.length() << endl;
//    cout << "string is: " << letters << endl;
    for(int  i = 0; i < 26; i++){
        alphabet[i] = 0;
    }
    for(int i = 1; i < letters.length()-1; i += 3){
//            cout << letters.at(i) << endl;
        alphabet[letters.at(i) - 'a'] = 1;
    }
    for(int  i = 0; i < 26; i++){
        ans += alphabet[i];
    }
    cout << ans;
}
