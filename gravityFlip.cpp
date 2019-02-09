#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int columns[n];
    for(int i = 0; i < n; i++){
        cin >> columns[i];
    }
    for(int i = 1; i < n; i++){ //looplarda sýkýntý var kolay bi sorun çoz eve gelince adým adým git problemi modelle
        for(int j = n-1; i <= j; j--){
            if(columns[j] < columns[j-1]){
                swap(columns[j], columns[j-1]);
            }

        }
    }
    for(int i = 0; i < n; i++){
        cout << columns[i] << " ";
    }
}

//WHY DIDNT YOUU JUST FUCKING SORT THE FUCKING ARRAY YOU FUCKING BRAINLESS MORON?? IS IT REALLY THAT HARD TO FUCKING SEE IT?
