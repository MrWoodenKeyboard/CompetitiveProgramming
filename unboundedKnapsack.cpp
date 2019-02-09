#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > memo;

int unboundedKnapSack(int w, int weights[], int values[], int n){
    if(w == 0){
        return 1;
    }
    if(n == 0){
        return 0;
    }
    if(weights[n] > w){
        return unboundedKnapSack(w, weights, values, n-1);
    }
    return memo[w][n] =  max( max(unboundedKnapSack(w, weights, values, n-1), values[n] + unboundedKnapSack(w-weights[n], weights, values, n-1)),  values[n] + unboundedKnapSack(w-weights[n], weights, values, n) );
}

int main(){
    int n = 4;
    int w = 80;
    int weights[] = {0, 10, 20, 30, 30};
    int values[] = {0, 80, 70, 120, 140};
    memo.resize(w+5, vector<int>(n+5));
/*    for(int i = 0; i < w; i++){
        memo[i].resize(n+5);
    }
    cout << "lelel";
*/    cout << unboundedKnapSack(w, weights, values, n);
}
