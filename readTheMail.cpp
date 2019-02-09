#include <iostream>
#include <string>
using namespace std;

int checkTheName(string name, string mail, int index){
    int i;
    for(i = 0; i < name.length(); i++){
        if(name.at(i) != mail.at(index + i)){
            return 0;
        }
    }
    return 1;
}

int main(){
    string name, mail;
    cin >> mail >> name;
    int ans = 0;
    for(int i = 0; i < mail.length(); i++){
//        cout << mail.length() - (name.length() + i) << endl;
        if(mail.at(i) == name.at(0) && mail.length() >= (name.length() + i) ){
//                cout << i << endl;
            ans += checkTheName(name, mail, i);
        }
    }
    cout << ans;
}
