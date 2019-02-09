#include <iostream>
#include <vector>
using namespace std;

void printVector(vector <int> v){
    for(int i = 0; i < v.size(); i++){
        cout << v.at(i) << " ";
    }
    cout << endl;
}


void allCombinationsUtil(int *arr, int len, int index, bool choose, vector <int> v){
    if(index >= len){
        return;
    }
    if(choose){
        v.push_back(arr[index]);
        printVector(v);
    }
    allCombinationsUtil(arr, len, index+1, true, v);
    allCombinationsUtil(arr, len, index+1, false, v);
}

void allCombinations(int *arr, int len){
    vector <int> v;
    allCombinationsUtil(arr, len, 0, true, v);
    allCombinationsUtil(arr, len, 0, false, v);
}

int main(){
    int n = 5;
    int arr[] = {1, 2, 3, 4, 5};
    allCombinations(arr, n);
}
