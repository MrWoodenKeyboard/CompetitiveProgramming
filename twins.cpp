#include <iostream>
#include <algorithm>

using namespace std;

void printArr(int arr[], int len){
    for(int i = 0; i < len; i++){
        cout << arr[i] << "\t";
    }
    cout << "\n";
}

int main(){
    int n, total = 0, stolen = 0, ans = 0;
    cin >> n;
    int coins[n];
    for(int i = 0; i < n; i++){
        cin >> coins[i];
        total += coins[i];
    }
    sort(coins, coins + n);
//    printArr(coins, n);
//    cout << "total: " << total << "  stolen: " << stolen << "   " << (stolen > total) << endl;
    while(!(stolen > total)){
//        cout << "total: " << total << "  stolen: " << stolen << endl;
        total -= coins[n-1];
        stolen += coins[n-1];
        n--;
        ans++;
    }
//    cout << "total: " << total << "  stolen: " << stolen << endl;
    cout << ans;
}
