#include <iostream>
using namespace std;

void printArr(int* arr, int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void enumerateUtil(int index, int len, int range, int *ar){
    if(index >= len){
        printArr(ar, len);
        return;
    }
    for(int i = 0; i <= range; i++){
        ar[index] = i;
        enumerateUtil(index + 1, len, range, ar);
    }
}

void enumerate(int len, int range){
    int *arr = (int*)malloc(sizeof(int)*len);
    enumerateUtil(0, len, range, arr);
}

int main(){
    enumerate(4, 5);
    return 0;
}
