#include <iostream>

using namespace std;

int main(){
    int x, y, maximum, chances;
    cin >> x >> y;
    maximum = max(x, y);
    chances = 7 - maximum;
    if(chances == 1){
        cout << "1/6";
    }
    else if(chances == 2){
        cout << "1/3";
    }
    else if(chances == 3){
        cout << "1/2";
    }
    else if(chances == 4){
        cout << "2/3";
    }
    else if(chances == 5){
        cout << "5/6";
    }
    else{
        cout << "1/1";
    }
}
