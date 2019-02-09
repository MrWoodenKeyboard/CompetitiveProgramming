#include <iostream>

using namespace std;

int main(){
    int x, y, moves = 0;
    int matrix[5][5];
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> matrix[i][j];
            if(matrix[i][j] == 1){
                x = i;
                y = j;
            }
        }
    }
    while(x != 2 || y != 2){
        if(x > 2){
            x--;
            moves++;
            continue;
        }
        if(x < 2){
            x++;
            moves++;
            continue;
        }
        if(y > 2){
            y--;
            moves++;
            continue;
        }
        if(y < 2){
            y++;
             moves++;
           continue;
        }
    }
    cout << moves;
}
