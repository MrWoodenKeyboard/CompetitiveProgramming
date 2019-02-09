#include <iostream>

using namespace std;

int main(){
    int sereja = 0, dima = 0, n, left = 0, right, temp;
    cin >> n;
    int cards[n];
    for(int i = 0; i < n; i++){
        cin >> cards[i];
    }
    right = n-1;
    for(int i = 0; i < n; i++){
        if(cards[left] > cards[right]){
            temp = cards[left];
            left++;
        }
        else{
            temp = cards[right];
            right--;
        }

        if(i%2 == 0){
            sereja = sereja + temp;
        }
        else{
            dima = dima + temp;
        }
    }
    cout << sereja << " " << dima;
}
