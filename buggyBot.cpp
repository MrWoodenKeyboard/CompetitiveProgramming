#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int l = 0, r = 0, u = 0, d = 0;
    char temp;
    for(int i = 0; i < n; i++){
        cin >> temp;
        if(temp == 'L'){
            l++;
        }
        else if(temp == 'R'){
            r++;
        }
        else if(temp == 'U'){
            u++;
        }
        else{
            d++;
        }
    }
//    cout << l << " " << r << " " << u << " " << d << endl;
    cout << min(l, r)*2 + min(u, d)*2;
}
