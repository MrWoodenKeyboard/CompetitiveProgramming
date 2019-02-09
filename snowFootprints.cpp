#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    char block;
    bool flag1 = 1;
    bool flag2 = 1;
    int first1 = 10000, last1 = 10000;
    int first2 = 10000, last2 = 10000;
    for(int i = 0; i < n; i++){
        cin >> block;
        if(block == 'R' && flag1){
            first1 = i;
            flag1 = 0;
        }
        if(block == 'R'){
            last1 = i + 1;
        }
        if(block == 'L' && flag2){
            last2 = i - 1;
            flag2 = 0;
        }
        if(block == 'L'){
            first2 = i;
        }
    }
    if(!flag1){
        cout << first1 + 1 << " " << last1 + 1;
    }
    else{
        cout << first2 + 1 << " " << last2 + 1;
    }
}
