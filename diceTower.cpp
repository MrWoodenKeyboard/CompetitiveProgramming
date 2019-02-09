#include <iostream>

using namespace std;


void printArr(int arr[], int len){
    for(int i = 0; i < len; i++){
        cout << arr[i] << "\t";
    }
    cout << "\n";
}


int main(){
    int n;
    cin >> n;
    int top;
    cin >> top;
    int bottom = 7 - top;
    int dice[6];//initialize
    int firstKnown, secondKnown, unknown;
    cin >> firstKnown >> secondKnown;
//    cout << "First bottom is: " << bottom << endl;
    for(int i = 1; i < n; i++){
        for(int i = 0; i < 6; i++){
            dice[i] = 0;
        }
        cin >> firstKnown >> secondKnown;
//        cout << "Numbers on the back are: " << 7-firstKnown << " and " << 7-secondKnown << endl;
        dice[firstKnown-1] = 1;
        dice[secondKnown-1] = 1;
        dice[7-firstKnown-1] = 1;
        dice[7-secondKnown-1] = 1;
//        printArr(dice, 6);
        for(int j = 0; j < n; j++){
            if(dice[j] == 0){
                unknown = j+1;
                break;
            }
        }
//        cout << "Unknowns are: " << unknown << " and " << 7-unknown << endl;
        if(unknown == bottom){
            bottom = 7-unknown;
        }
        else if(7-unknown == bottom){
            bottom = unknown;
        }
        else{
            cout << "NO";
            return 0;
        }
//        cout << "New bottom is: " << bottom << endl;
    }
    cout << "YES";
}
