#include <iostream>

using namespace std;

int main(){
    int k, r, i = 1;
    cin >> k >> r;
//    cout << (i*k)%10 << endl << ((i*k)-r)%10 << endl;
    for(;!((i*k)%10 == 0) && !(((i*k)-r)%10 == 0); i++){
//        cout << "i = " << i << endl;
    }
    cout << i;
}
