#include <iostream>
#include <string>
using namespace std;

int main(){
    int n, a = 0, d = 0;
    string games;
    cin >> n >> games;
    for(int i = 0; i < n; i++){
        if(games.at(i) == 'A'){
            a++;
        }
        else{
            d++;
        }
    }
    if(a > d){
        cout << "Anton";
    }
    else if(a < d){
        cout << "Danik";
    }
    else{
        cout << "Friendship";
    }
}
