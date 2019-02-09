#include <iostream>

using namespace std;

int main(){
    int n, k;
    char letter;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        letter = 'a' + (i%k);
        cout << letter;
    }
}
