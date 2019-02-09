#include <iostream>
using namespace std;

int main(){
    int n, temp;
    cin >> n;
    int mini = 2147483000, maxi = 0, minCount = 0, maxCount = 0;
    if(n == 1 || n == 2){
        cout << "0";
        return 0;
    }
    for(int i = 0; i < n; i++){
        cin >> temp;
//        cout << "temp: " << temp << "  max: " << maxi << "  min: " << mini << endl;
        if(temp > maxi){
            maxi = temp;
            maxCount = 1;
//            cout << "new max\n";
        }
        else if(temp == maxi){
            maxCount++;
//             cout << "same max\n";
       }
        if(temp < mini){
            mini = temp;
            minCount = 1;
//            cout << "new min\n";
        }
        else if(temp == mini){
            minCount++;
        }
//            cout << "same min\n";
    }
//    cout << "  max: " << maxi << "  min: " << mini << endl;
    if(maxi == mini){
        cout << "0";
        return 0;
    }
    cout << n - (maxCount + minCount);
}
