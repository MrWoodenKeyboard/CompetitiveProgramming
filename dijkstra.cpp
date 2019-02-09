#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

void printVector(vector <int> v){
    for(int i = 0; i < v.size(); i++){
        cout << v.at(i) << "  ";
    }
    cout << endl;
}

void delByValue(vector <int> *v, int n){//doesn't work when the element is not present
    vector<int>::iterator it;
    for(it = (*v).begin(); it <= (*v).end(); it++){
        if(*it == n){
            break;
        }
    }
    if(it != (*v).end()){
        (*v).erase(it);
    }
    return;
}


int main(){
    vector <int> v;
    for(int i = 0; i < 10; i++){
        v.push_back(i);
    }
    printVector(v);
    delByValue(&v, 5);
    printVector(v);
    delByValue(&v, 5);
    delByValue(&v, 5);
    delByValue(&v, 5);
    delByValue(&v, 5);
    printVector(v);
}
