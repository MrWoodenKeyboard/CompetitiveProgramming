#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int p;
    cin >> p;
    int first[p];
    for(int i = 0; i < p; i++){
        cin >> first[i];
    }
    int q;
    cin >> q;
    int second[q];
    for(int i = 0; i < q; i++){
        cin >> second[i];
    }
    bool notPresent = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < p; j++){
            if(first[j] == i){
                notPresent = 0;
            }
        }
        for(int j = 0; j < q; j++){
            if(second[j] == i){
                notPresent = 0;
            }
        }
        if(notPresent == 1){
            cout << "Oh, my keyboard!";
            return 0;
        }
        notPresent = 1;
    }
    cout << "I become the guy.";
    return 0;
}
