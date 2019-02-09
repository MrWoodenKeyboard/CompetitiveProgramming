#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    string word;
    cin >> word;
    int prev = n - 1, current = n, flag = 1;
    while(prev != current || flag == 1){
//            cout << "WTF\n";
        for(int i = 0; i < word.length()-1; i++){
//                cout << i << "  " << word.length() << endl;
            if(word.at(i) == '0' && word.at(i+1) == '1'){
                word.erase(i, 2);
                i -= 2;
            }
            else if(word.at(i) == '1' && word.at(i+1) == '0'){
                word.erase(i, 2);
                i -= 2;
            }
        flag = 0;
        prev = current;
        current = word.length();
        }
        if(word.length() < 2){
            cout << word.length();
            return 0;
        }
    }
    cout << word.length();
}
