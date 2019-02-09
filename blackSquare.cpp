#include <iostream>
#include <string>
using namespace std;

int main(){
    int first, second, third, fourth, calories = 0;
    cin >> first >> second >> third >> fourth;
    string process;
    cin >> process;
    for(int i = 0; i < process.length(); i++){
        if(process.at(i) == '1'){
            calories = calories + first;
        }
        if(process.at(i) == '2'){
            calories = calories + second;
        }
        if(process.at(i) == '3'){
            calories = calories + third;
        }
        if(process.at(i) == '4'){
            calories = calories + fourth;
        }
    }
    cout << calories;
}
