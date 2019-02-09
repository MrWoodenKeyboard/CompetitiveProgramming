#include <iostream>

using namespace std;

void printArr(int arr[], int len){
    for(int i = 0; i < len; i++){
        cout << arr[i] << "\t";
    }
    cout << "\n";
}

void mergeThem(int arr1[], int len1, int arr2[], int len2, int arr3[]){
    int index1 = 0;
    int index2 = 0;
    int index3 = 0;
  //  cout << "First array:\t";
  //  printArr(arr1, len1);
 //   cout << "Second array:\t";
  //  printArr(arr2, len2);
    while(index1 < len1 && index2 < len2){
    //        cout << "Both arrays still have elements\n";
        if(arr1[index1] <= arr2[index2]){
    //        cout << "Passing from left array\n";
            arr3[index3] = arr1[index1];
            index3++;
            index1++;
        }
        else{
     //       cout << "Passing from left array\n";
            arr3[index3] = arr2[index2];
            index3++;
            index2++;
        }
    }
    while(index1 < len1){
   //     cout << "Only arr1 has elements\n";
        arr3[index3] = arr1[index1];
        index3++;
        index1++;
    }
    while(index2 < len2){
 //       cout << "Only arr1 has elements\n";
        arr3[index3] = arr2[index2];
        index3++;
        index2++;
    }
  //  cout << "Merged array:\t";
   // printArr(arr3, len1 + len2);
}

void mergeSort(int arr[], int len){
    if(len < 2){
        return;
    }
    int mid = len/2;
    int left[len/2];
    int right[len - (len/2)];
    for(int i = 0; i < mid ; i++){
        left[i] = arr[i];
    }
//    cout << "Left array:\t";
//    printArr(left, len/2);
    for(int i = mid,  j = 0; i < len; i++, j++){
        right[j] = arr[i];
    }
  //  cout << "Right array:\t";
  //  printArr(right, len - (len/2));
    mergeSort(left, len/2);
    mergeSort(right, len - (len/2));
    mergeThem(left, len/2, right, len - (len/2), arr);
}

int main(){
    int arr[] = {2, 1, 10, 0, 6, 8, 9, 4, 3, 7};
    printArr(arr, 10);
    mergeSort(arr, 10);
    printArr(arr, 10);


}

