#include <iostream>
#include <iostream>

using namespace std;

int knapSack(int w, int weights[], int values[], int n){
    if(w == 0 || n == 0){
        return 0;
    }
    if(weights[n] > w){
        return knapSack(w, weights, values, n-1);
    }
    return max( knapSack(w, weights, values, n-1), values[n] + knapSack(w-weights[n] ,weights, values, n-1) );
}

int main(){
    int w = 50;
    int n = 3;
    int values[] = {0, 60, 100, 120};
    int weights[] = {0, 10, 20, 30};
    cout << knapSack(w, weights, values, n);
}
