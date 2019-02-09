#include <iostream>

using namespace std;

int main(){
    int color[4], change[3] = {0, 0, 0}, total;
    cin >> color[0] >> color[1] >> color[2] >> color[3];
    for(int i = 0; i < 4 ; i++){
        for(int j = i + 1; j < 4; j++){
            if(color[i] == color[j]){
                change[i] = 1;
//                cout << "i: " << i << "j: " << j << endl;
            }
        }
    }
    total = change[0] + change[1] + change[2];
    cout << total;
}
