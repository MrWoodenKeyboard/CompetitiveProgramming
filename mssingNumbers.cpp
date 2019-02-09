#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void addIfNotThere(int n, vector <int> *v){
    bool flag = 0;
    for(int i = 0; i < (*v).size(); i++){
        if((*v).at(i) == n){
            flag = 1;
            break;
        }
    }
    if(!flag){
        (*v).push_back(n);
    }
}

void printVector(vector <int> v){
    for(int i = 0; i < v.size(); i++){
        cout << v.at(i) << " ";
    }
}

int main(){
    int len1, len2;
    cin >> len1;
    int arr1[len1];
    for(int i = 0; i < len1; i++){
        cin >> arr1[i];
    }
    cin >> len2;
    int arr2[len2];
    for(int i = 0; i < len2; i++){
        cin >> arr2[i];
    }
    sort(arr1, arr1+len1);
    sort(arr2, arr2+len2);
    int i = 0, j = 0;
    vector <int> missing;
    while(j < len2){
        if(arr1[i] == arr2[j]){
            i++;
            j++;
        }
        else{
            addIfNotThere(arr2[j], &missing);
            j++;
        }
    }
    printVector(missing);
}
