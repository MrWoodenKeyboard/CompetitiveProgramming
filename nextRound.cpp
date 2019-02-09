#include <iostream>

using namespace std;

int main(){
    int k, n;
    cin >> n >> k;
    k--;
    int contestants[n];
    for(int i = 0; i < n; i++){
        cin >> contestants[i];
    }
    if(contestants[k] > 0){
//            cout << "if\n";
        while(contestants[k] == contestants[k+1] && k < n - 1){
            k++;
//    cout << "equal\n";
        }
        cout << k + 1;
    }
    else{
//            cout << "else\n";
        for(k = -1; contestants[k + 1] > 0; k++);
        cout << k + 1;
    }
}
