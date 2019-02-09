#include <iostream>
#include <vector>
#include <utility>
//doesnt and wont work
using namespace std;

vector<vector<int> > grid;

struct coordinate{
    int a;
    int b;
};

typedef struct coordinate coordinate;

int main(){

    int n;
    cin >> n;
    grid.resize(n, vector<int>(n));

    vector<coordinate> cavities;
    coordinate temp;
    int current, up, down, left, right;
    vector<int> numbers;
    int row;
    for(int i = 0; i < n; i++){
        cin >> row;
        numbers.push_back(row);
    }

    for(int i = 0; i < n; i++){
        for(int j = n-1; j >= 0; j--){
            grid[i][j] = numbers[i]%10;
            numbers[i] /= 10;
        }
    }

    for(int i = 1; i < n-1; i++){
        for(int j = 1; j < n-1; j++){
            current = grid[i][j];
            up = grid[i+1][j];
            down = grid[i-1][j];
            left = grid[i][j-1];
            right = grid[i][j+1];

            if( current > up && current > down && current > left && current > right ){
                temp.a = i;
                temp.b = j;
                cavities.push_back(temp);
            }
        }
    }

    for(int i = 0; i < cavities.size(); i++){
        grid[ cavities[i].a ][ cavities[i].b ] = -1;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
//            cout << "coordinates: " << i << "  " << j << endl;
            if( grid[i][j] == -1 ){
                cout << "X";
            }
            else{
                cout << grid[i][j];
            }
        }
        cout << "\n";
    }
}
