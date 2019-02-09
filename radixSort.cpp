#include <iostream>
#include <cmath>;
using namespace std;

void printArr(int arr[], int len){
    for(int i = 0; i < len; i++) {
        cout << arr[i] << "  ";
    }
    printf("\n");
}

int power(int base, int power){
    int ans = 1;
    for(int i = 0; i < power; i++){
        ans = ans*base;
    }
    return ans;
}

int findMax(int arr[], int len){
    int max = arr[0];
    for(int i = 1; i < len; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

int findDigits(int a, int base){
    int digit = 1;
    for(int i = base; a/i != 0; i = i*base){
        digit++;
    }
    return digit;
}

int numberOnDesiredDigit(int a, int base, int digit){
//    cout << "Entered numberOnDesiredDigit with:  " << a << endl;
    if(digit == 1){
        return a%base;
    }
    return (a/(power(base, (digit-1))))%base;
}

int* countSortDigit(int arr[], int len, int base, int digit){
    int auxArr[base];
    int *sortedArray = new int[len];
    for(int i = 0; i < base; i++){
        auxArr[i] = 0;
    }
    for(int i = 0; i < len; i++){
        int n = numberOnDesiredDigit(arr[i], base, digit);
        auxArr[n]++;
//        printArr(auxArr, base);
    }
//    printArr(auxArr, base);
    //auxArr is good
    for(int i = 1; i < base; i++){
        auxArr[i] = auxArr[i] + auxArr[i-1];
    }
    for(int i = 0; i < base; i++){
        auxArr[i]--;
    }
//    printArr(auxArr, base);
    for(int i = len - 1; i >= 0; i--){
//        cout << "Hey" << endl;
        int n = numberOnDesiredDigit(arr[i], base, digit);
        sortedArray[auxArr[n]] = arr[i];
        auxArr[n]--;
    }
    return sortedArray;
}

int* radixSort(int arr[], int len, int base){
    int max = findMax(arr, len);
//    cout << "Max number:  " << max << endl;
    int digit = findDigits(max, base);
//    cout << "Max digit:  " << digit << endl;
    for(int i = 1; i <= digit; i++){
        arr = countSortDigit(arr, len, base, i);
        printArr(arr, len);
    }
    return arr;
}

int main(){
    int arr[100] = {21,	6,	40,	32,	93,	60,	40,	66,	80,	98,	59,	79,	96,	36,	58,	67,	4,	72,	67,	85,	35,	26,	4,	42,	4,	38,	72,	84,	100,	7,	92,	67,	98,	55,	68,	35,	62,	82,	40,	71,	100,	47,	14,	4,	55,	83,	17,	83,	91,	35,	5,	39,	53,	30,	26,	35,	58,	68,	12,	70,	75,	58,	70,	40,	1,	52,	57,	44,	9,	45,	58,	12,	66,	26,	27,	4,	96,	12,	93,	24,	23,	78,	93,	2,	9,	2,	74,	100,	66,	98,	45,	48,	2,	73,	92,	52,	93,	55,	9,	96};
    int *sortedArr;
    printArr(arr, 100);
    sortedArr = radixSort(arr, 100, 10);
 //   cout << "outside\n";
    printArr(sortedArr, 100);

}
