#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int cities[n];
    for(int i = 0; i < n; i++){
        cin >> cities[i];
    }
    cout << cities[1] - cities[0] << " " << cities[n-1] - cities[0] << endl;
    for(int i = 1; i < n-1; i++){
        cout << min(cities[i] - cities[i-1], cities[i+1] - cities[i]) << " " << max(cities[i] - cities[0], cities[n-1] - cities[i]) << endl;
    }
    if(n != 1){
        cout << cities[n-1] - cities[n-2] << " " << cities[n-1] - cities[0];
    }
}
