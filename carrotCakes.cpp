#include <iostream>

using namespace std;

int main(){
    int need, bakingTime, bakingNumber, secondOvenTime, time1,currentCakes = 0;
    cin >> need >> bakingTime >> bakingNumber >> secondOvenTime;
    for(time1 = 0; currentCakes < need; time1 += bakingTime, currentCakes += bakingNumber){}
//    cout << "time1: " << time1 << endl;
    if(secondOvenTime < time1 - bakingTime){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}
