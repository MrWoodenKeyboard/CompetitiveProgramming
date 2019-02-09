#include <iostream>
#include <vector>

using namespace std;



int main(){
    int n, q;
    cin >> n >> q;
    vector<vector<int> > sequences(n);
    int type, x, y;
    int lastAnswer = 0;
    for(int i = 0; i < q; i++){
        cin >> type >> x >> y;
        int index = (x^lastAnswer)%n;
        if(type == 1){
            sequences[index].push_back(y);
        }

        else{
            lastAnswer = sequences[index][ y % sequences[index].size() ];
            cout << lastAnswer << endl;
        }
    }
}
