#include <iostream>

using namespace std;

void selectionSort(int arr[], int len){
    for(int i = 0; i < len; i++){
  //      cout << "Index is at " << i << endl;
        for(int j = i; j < len; j++){
//            cout << "Current index value:  " << arr[j] << endl;
            if(arr[j] < arr[i]){
  //              cout << "Found a smaller value. Swapping" << endl;
                swap(arr[i], arr[j]);
            }
        }
//        cout << i << "th element is now " << arr[i] << endl;
    }
}

void printArr(int arr[], int len){
    for(int i = 0; i < len; i++) {
        cout << arr[i] << "  ";
    }
    printf("\n");
}

int main(){
    int arr[100] = {21,	6,	40,	32,	93,	60,	40,	66,	80,	98,	59,	79,	96,	36,	58,	67,	4,	72,	67,	85,	35,	26,	4,	42,	4,	38,	72,	84,	100,	7,	92,	67,	98,	55,	68,	35,	62,	82,	40,	71,	100,	47,	14,	4,	55,	83,	17,	83,	91,	35,	5,	39,	53,	30,	26,	35,	58,	68,	12,	70,	75,	58,	70,	40,	1,	52,	57,	44,	9,	45,	58,	12,	66,	26,	27,	4,	96,	12,	93,	24,	23,	78,	93,	2,	9,	2,	74,	100,	66,	98,	45,	48,	2,	73,	92,	52,	93,	55,	9,	96};
    printArr(arr, 100);
    selectionSort(arr, 100);
    printArr(arr, 100);
}
