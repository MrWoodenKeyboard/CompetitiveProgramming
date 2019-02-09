#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printVector(vector <char> v){
    for(int i = 0; i < v.size(); i++){
        cout << v.at(i);
    }
}

int main(){
    string balance, weights;
    cin >> balance >> weights;
    vector <char> left;
    vector <char> right;
    int i;
    for(i = 0; balance.at(i) != '|'; i++){
        left.push_back(balance.at(i));
    }
    i++;
    for(;i < balance.length(); i++){
        right.push_back(balance.at(i));
    }
    for(int j = 0; j < weights.length(); j++){
        if(right.size() < left.size()){
            right.push_back(weights.at(j));
        }
        else{
            left.push_back(weights.at(j));
        }
    }
    if(right.size() != left.size()){
        cout << "Impossible";
    }
    else{
        printVector(left);
        cout << "|";
        printVector(right);
    }
}
