#include <iostream>
#include <string>
using namespace std;

bool contains(string body, int index, string object){
    for(int i = 0; i < object.length(); i++){
        if(body.at(index + i) != object.at(i)){
            return false;
        }
    }
    return true;
}

void findPatterns(string body, string object){
    for(int i = 0; object.length() <= (body.length() - i); i++){
        if(object.at(0) == body.at(i)){
            if(contains(body, i, object)){
                cout << i << endl;
            }
        }
    }
}

int main(){
    string body, object;
    cin >> body >> object;
    findPatterns(body, object);
}
