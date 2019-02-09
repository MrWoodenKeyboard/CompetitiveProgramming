//HAYATIMDA YAZDIÐIM EN GARÝP KOD NEDEN  -48 GEREKTÝ ANLAMIYORUM KAFAYI YÝCEM NERDEN GELÝYOR O EKSTRA YEMÝN EDERÝM ANLAMIYORUM
//BU NE AMINA KOYÝM
//GERÝZEKALI OÇ ÇÜNKÜ ASCII DEÐERLERÝ
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void printArr(int arr[], int len){
    for(int i = 0; i < len; i++){
        cout << arr[i] << "\t";
    }
    cout << "\n";
}

int main(){
    string calculation;
    cin >> calculation;
    int numbers[(calculation.length()/2)+1];
//    cout << "length: " << (calculation.length()/2)+1 << endl;
    for(int i = 0, j = 0; i < calculation.length(); i += 2, j++){
//        cout << "number being pushed: " << calculation.at(i) << "  at: " << j << endl;
        numbers[j] = calculation.at(i);
    }
//    printArr(numbers, (calculation.length()/2)+1);
    sort(numbers, numbers + (calculation.length()/2)+1);
//    printArr(numbers, (calculation.length()/2)+1);
    for(int i = 0; i < (calculation.length()/2)+1; i++){
        cout << numbers[i] - 48;
        if(i != (calculation.length()/2)){
            cout << "+";
        }
    }
}
