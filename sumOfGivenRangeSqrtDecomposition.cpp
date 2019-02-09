#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector <int> dc;
int lenOfB;
void printVector(vector <int> v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

void build(int arr[], int len){
    lenOfB = floor(sqrt(len));
//    cout << lenOfB << endl;
    dc.resize( len/lenOfB + 1 , 0);
//    cout << "vector created" << endl;
    int t = -1;
    for(int i = 0; i < len; i++){
        if((i+1)%lenOfB == 1){
            t++;
        }
        dc[t] += arr[i];
    }
//    cout << "end of build" << endl;
}

int query(int arr[], int l, int r){
    int sum = 0;
    for(; l%lenOfB != 0; l++){
//        cout << "adding " << arr[l] << endl;
        sum += arr[l];
    }
//    cout << "1 ended" << endl;
    while(l + lenOfB <= r){
//        cout << "adding " << dc[ l/lenOfB ] << endl;
        sum += dc[ l/lenOfB ];

        cout << l << endl;
        l += lenOfB;
    }
//    cout << "2 ended" << endl;
    for(; l <= r; l++){
//        cout << "adding " << arr[l] << endl;
        sum += arr[l];
    }
    return sum;
}

void update(int index, int val ,int arr[]){
    dc[index/lenOfB] -= arr[index];
    arr[index] = val;
    dc[index/lenOfB] += arr[index];
}

int main(){
    int arr[] = {1, 5, 2, 4, 6, 1, 3, 5, 7, 10};
    int len = sizeof(arr)/sizeof(arr[0]);
    build(arr, len);
//    printVector(dc);
    cout << query(arr, 8,8) << endl;
    update(8, 0, arr);
    cout << query(arr, 8,8) << endl;
}
