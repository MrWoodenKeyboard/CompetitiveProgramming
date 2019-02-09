#include <iostream>

using namespace std;

int main(){
    int r, g;
    cin >> r >> g;
    int least = min(r, g);
    for(int i = 1; i <= least; i++){
        if( r%i == 0 && g%i == 0 ){
            cout << i << " " << r/i << " " << g/i << endl;
            /*
            if(r%(r/i) == 0 && g%(g/i) == 0){
                cout << i << " " << r/(r/i) << " " << g/(g/i) << endl;
            }
            */
        }
    }
}
