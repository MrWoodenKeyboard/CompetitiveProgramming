#include <iostream>

using namespace std;
/*not even necessary
int howManyTwos(int n){
    int totalNumber = 0;
    while(n%2 == 0){
        totalNumber++;
        n = n/2;
    }
    return totalNumber;
}
*/

/*very very long solution
int howManyFives(int n){
    int totalNumber = 0;
    while(n%5 == 0){
        totalNumber++;
        n = n/5;
    }
    return totalNumber;
}
*/



int Z(int n){
    int numberOfFives = 0;
    for(int i = 5; n/i >= 1; i = i*5){
        numberOfFives = numberOfFives + n/i;
    }
    return numberOfFives;
}

int main(){
    int t, number;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> number;
        cout << Z(number) << endl;
    }

}
