#include <iostream>
#include <stack>
#include <string>

using namespace std;

void printStack(stack <char> s){
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    stack <char> s;
    string seq;
    int flag = 0;
    for(int i = 0; i  < t; i++){
        cin >> seq;
//        cout << "sequence is: " << seq << endl;
        for(int j = 0; j < seq.length(); j++){
//                cout << "at index: " << j << endl;
//                cout << "current stack: ";
//                printStack(s);

            if( seq.at(j) == '(' || seq.at(j) == '[' || seq.at(j) == '{' ){
//                cout << "adding " << seq.at(j) << endl;
                s.push( seq.at(j) );
            }
            else{
                if(s.empty()){
                    flag = 1;
                    cout << "NO" << endl;
                    break;
                }
                if( ( seq.at(j) == ')' && s.top() == '(' ) || ( seq.at(j) == ']' && s.top() == '[' ) || ( seq.at(j) == '}' && s.top() == '{' ) ){
//                    cout << "popping " << s.top() << endl;
                    s.pop();
                }
                else{
                    flag = 1;
//                    cout << "non-matching parantheses" << endl;
                    cout << "NO" << endl;
                    break;
                }
            }
        }
        if(flag == 0){
            if(s.empty()){
                cout << "YES" << endl;
            }
            else{
//                    cout << "s is still not empty" << endl;
//                    cout << "printing the lefovers " << endl;
//                    printStack(s);
                cout << "NO" << endl;
            }
        }
        flag = 0;
        while(!s.empty()){
            s.pop();
        }
    }
}
