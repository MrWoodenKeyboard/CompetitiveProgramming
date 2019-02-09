#include <iostream>
#include <climits>
using namespace std;

int kadane(int *arr, int len){
    //checking if all the elements are negative, if so, print the largest element
    int indicator = 0;
    for(int i = 0; i < len; i++){
        if(arr[i] > 0){
            indicator = 1;
        }
    }
    if(indicator == 0){
            int greatest = arr[0];
        for(int i = 1; i < len; i++){
            greatest = max(greatest, arr[i]);
        }
        return greatest;
    }

    int sum = 0;
    int ans = 0;
    for(int i = 0; i < len; i++){
        if(sum < 0){
            sum = 0;
        }

        sum = sum + arr[i];
        ans = max(sum, ans);
        cout << "Current sum: " << sum << "\tCurrent ans: " << ans << endl;
    }
    return ans;
}

int main(){
    int arr1[] = {3, 1, -5, 7, -3, 2, 3, 5, -2, 8};
    cout << kadane(arr1, 10) << endl;
    int arr2[] = {-20, -5, -10, -2, -14};
    cout << kadane(arr2, 5) << endl;

}
