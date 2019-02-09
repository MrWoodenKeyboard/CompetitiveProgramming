#include <iostream>
#include <string>
#include <stack>
using namespace std;

void print_stack(stack<char> c) {
    while (!c.empty()) {
        std::cout<<c.top();
        c.pop();
    }
}

bool hasHigherPrecedence(char operator1, char operator2){
    if(operator1 == '('){
        return false;
    }
    else if(operator1 == '+' || operator1 == '-'){
        if(operator2 == '+' || operator2 == '-'){
            return true;
        }
        return false;
    }
    else if((operator1 == '*' || operator1 == '/')){
        if(operator2 == '+' || operator2 == '-' || operator2 == '*' || operator2 == '/'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(operator1 == '^'){//when the char is ^
        if(operator2 == '+' || operator2 == '-' || operator2 == '*' || operator2 == '/' || operator2 == '^'){
            return true;
        }
        else{
            return false;
        }

    }
}

void infixToPostfix(string infix){
//    cout << "    In da func!    ";
    stack<char> operators;
    for(int i = 0; i < infix.length(); i++){
//        cout << "current element:  " << infix.at(i) << "    ";
        if(infix.at(i) == '+' || infix.at(i) == '-' || infix.at(i) == '*' || infix.at(i) == '/' || infix.at(i) == '^'){
//            cout << "    An operator in the string!    ";
            if(operators.empty()){
                operators.push(infix.at(i));
            }
            else if(operators.top() == '+' || operators.top() == '-' || operators.top() == '*' || operators.top() == '/' || operators.top() == '^'){
//                cout << "    The stack also has an operator!    ";
                while(!operators.empty() && hasHigherPrecedence(operators.top(), infix.at(i))){//normalde top() istemek undefined behavior when the stack is empty ama ben onu 2. condition yapıp bundan sıyrıldım
//                    cout << "    The stack operator has higher precedence!   ";
                    cout << operators.top();
                    operators.pop();
                }
//                cout << "    higher precedence operator are finished in the stack. now pushing the operator    ";
                operators.push(infix.at(i));
            }
            else{
//                cout << "    The stack doesn't have an operator!    ";
                operators.push(infix.at(i));
            }
        }
        else if(infix.at(i) == ')'){
            while(operators.top() != '(' && !operators.empty()){
                cout << operators.top();
                operators.pop();
            }
            if(!operators.empty()){
                operators.pop();
            }
        }
        else if(infix.at(i) == '('){
            operators.push(infix.at(i));
        }
        else{
            cout << infix.at(i);
        }
//        cout << "    stack is:    ";
//        print_stack(operators);
//        cout << "    ";
    }
    while(!operators.empty()){
        cout << operators.top();
        operators.pop();
    }
}

int main(){
    int t;
    cin >> t;
    string infix ;
    for(int i = 0; i < t; i++){
        cin >> infix;
        infixToPostfix(infix);
        cout << endl;
    }

//    infixToPostfix(infix);
}
