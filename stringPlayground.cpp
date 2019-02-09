#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
int highest(int* arr, int len){
    int highest = arr[0];
    for(int i = 1; i < len; i++){
        if(arr[i] > highest){
            highest = arr[i];
        }
    }
    return highest;
}
*/

void printArr(int arr[], int len){
    for(int i = 0; i < len; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
//    char a = 'j';
//    a = a-5;
    int a;
    cin >> a;
    cout << a;
}
/*
int length1 = parts[0].length();
    int length2 = parts[1].length();
    int length3 = parts[2].length();
    if(length1 == length2 == length3){
        return parts;
    }
    int lengths[3] = {length1, length2, length3};
    int greatest = highest(lengths, 3);
    if(greatest == length1){

    }
    return parts;
*/
