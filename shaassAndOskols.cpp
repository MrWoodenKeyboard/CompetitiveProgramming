#include <iostream>

using namespace std;

void shoot(int x, int y, int wires[], int len){
//    cout << "entered shoot with  " << "x= " << x << "  y= " << y << endl;
    if(y == 0){
        wires[1] += wires[y] - x;
        wires[0] = 0;
        return;
    }
    if(y == len - 1){
        wires[len - 2] += x - 1;
        wires[len - 1] = 0;
        return;
    }
    wires[y + 1] += wires[y] - x;
    wires[y - 1] += x - 1;
    wires[y] = 0;
    return;
}

int main(){
    int n, m, x, y;
    cin >> n;
    int wires[n];
    for(int i = 0 ; i < n; i++){
        cin >> wires[i];
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> y >> x;
        y--;
        shoot(x, y, wires, n);
     //   cout << "n is: " << n << endl;
    //    cout << "printing wires: " << endl;

  //      cout << endl;
    }
    for(int i = 0; i < n; i++){
//            cout << "i = " << i << endl;
        cout << wires[i] << endl;
    }
}
