#include <iostream>
#include <string>
using namespace std;


void printArr(int arr[], int len){
    for(int i = 0; i < len; i++){
        cout << arr[i] << "\t";
    }
    cout << "\n";
}


bool goodNumber(string number, int k){
    int value;
    int digits[10];///initialize
//    cout << "the number is " << number << endl;
    for(int i = 0; i < 10; i++){
        digits[i] = 0;
    }
//    printArr(digits, 10);
    for(int i = 0; i < number.length(); i++){
        value = number.at(i) - 48;
//        if(value > k){
//            return false;
//        }
        digits[value] = 1;
    }
//    printArr(digits, 10);
    for(int i = 0; i <= k; i++){
        if(digits[i] == 0){
            return false;
        }
    }
    return true;
}

int main(){
    string number;
    int n, k, ans = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> number;
        if(goodNumber(number, k)){
            ans++;
        }
    }
    cout << ans;
}
