#include <iostream>

using namespace std;

int main(){
    int n, l;
    cin >> n >> l;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
/*
    for(int i = 0; i < n; i++){
        cout << arr[i] << "  ";
    }
    cout << endl;
*/
    int minW = 2147483647;
    int minI;
    int weight = 0;
    for(int j = 0; j < l; j++){
        weight += arr[j];
    }
    minW = weight;
    minI = 0;
    for(int i = 1; i < n-l+1; i++){
        weight -= arr[i-1];
        weight += arr[i+l-1];
//        cout << weight << endl;
//        cout <<   arr[i] << "  " << arr[i+1] << "  " << arr[i+2] << endl;
//        cout << "weight at " << i << " is " << weights[i] << endl;
        if(weight < minW){
            minW = weight;
            minI = i;
        }
    }
    cout << minI+1;
}
