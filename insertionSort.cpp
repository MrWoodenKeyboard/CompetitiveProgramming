#include <iostream>

using namespace std;

void insertionSort(int arr[], int len){
    for(int i = 1; i < len; i++){
        int value = arr[i];
        for(int j = i - 1; j >= 0; j--){
            if(value < arr[j]){
                arr[j + 1] = arr[j];
                if(j == 0){
                    arr[0] = value;
                    cout << "smallest value:  " << value << endl;
                }
            }
            else{
                arr[j + 1] = value;
                break;
            }
        }
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
    insertionSort(arr, 100);
    printArr(arr, 100);
}
