#include <iostream>
#include <string>

using namespace std;

int main(){
    char direction;
    string message, keyboard = "qwertyuiopasdfghjkl;zxcvbnm,./";
    cin >> direction >> message;
    for(int i = 0; i < message.length(); i++){
        for(int j = 0; j < keyboard.length(); j++){
//            cout << "i : " << i << "  j: " << j << endl;
            if(message.at(i) == keyboard.at(j)){
//                cout << "FOUND IT!\n";
                if(direction == 'R'){
                    cout << keyboard.at(j-1);
                }
                else{
                    cout << keyboard.at(j+1);
                }
                break;
            }
        }
    }
}
