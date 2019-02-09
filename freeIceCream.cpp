#include <iostream>
using namespace std;

int main(){
    int n, distress = 0;
    long long int x, number;
    char sign;
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> sign >> number;
        if(sign == '+'){
            x += number;
        }
        else if(x >= number){
            x -= number;
        }
        else{
            distress++;
        }
//        cout << x << endl;
    }
    cout << x << " " << distress;
}
