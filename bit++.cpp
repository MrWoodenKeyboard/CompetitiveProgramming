#include <iostream>
#include <string>
using namespace std;

int main(){
    int n, x = 0;
    cin >> n;
    string operation;
    for(int i = 0; i < n; i++){
        cin >> operation;
        if(operation.at(0) == '+' || operation.at(2) == '+'){
            x++;
        }
        else{
            x--;
        }
    }
    cout << x;
}
