#include <iostream>

using namespace std;


void printArr(int arr[], int len){
    for(int i = 0; i < len; i++) {
        cout << arr[i] << "  ";
    }
    printf("\n");
}

int partitionQS(int arr[], int startIndex, int endIndex){
//    cout << "Entered partition with arr:  ";
//    printArr(arr, endIndex - startIndex + 1);
    int pivot = arr[endIndex];
//    cout << "Pivot is:  " << pivot << endl;
    int pIndex = 0;
    for(int i = 0; i < endIndex; i++){
        if(arr[i] <= pivot){
            swap(arr[i], arr[pIndex]);
            pIndex++;
//            cout << "Current pIndex:  " << pIndex << endl;
        }
    }
    swap(arr[pIndex], arr[endIndex]);
  //  cout << "Partitioned array:  ";
 //   printArr(arr, endIndex - startIndex + 1);
    return pIndex;
}

void quickSort(int arr[], int startIndex, int endIndex){
 //   cout << "Entered quickSort with:  ";
 //   printArr(arr, endIndex - startIndex + 1);
    if(startIndex >= endIndex){
    //        cout << "One element or invalid request. Returning." << endl;
        return;
    }
    int pIndex = partitionQS(arr, startIndex, endIndex);
    quickSort(arr, startIndex, pIndex - 1);
    quickSort(arr, pIndex + 1, endIndex);
}


int main(){
    int arr[100] = {21,	6,	40,	32,	93,	60,	40,	66,	80,	98,	59,	79,	96,	36,	58,	67,	4,	72,	67,	85,	35,	26,	4,	42,	4,	38,	72,	84,	100,	7,	92,	67,	98,	55,	68,	35,	62,	82,	40,	71,	100,	47,	14,	4,	55,	83,	17,	83,	91,	35,	5,	39,	53,	30,	26,	35,	58,	68,	12,	70,	75,	58,	70,	40,	1,	52,	57,	44,	9,	45,	58,	12,	66,	26,	27,	4,	96,	12,	93,	24,	23,	78,	93,	2,	9,	2,	74,	100,	66,	98,	45,	48,	2,	73,	92,	52,	93,	55,	9,	96};
    printArr(arr, 100);
    quickSort(arr, 0, 99);
    printArr(arr, 100);

}
