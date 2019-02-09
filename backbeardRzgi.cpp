#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <long long> numbers;
vector <long long> temp;

void printV(vector <long long> v, int a, int b){
    for(int i = a; i <= b; i++){
        cout << v[i] << "  ";
    }
    cout << endl;
}

long long merge(int l, int r, int mid){
    cout << "inside merge with   " << l << "  " << mid << "  " << r << ":" << endl;
    printV(numbers, l, mid);
    cout << "and" << endl;
    printV(numbers, mid+1, r);
    long long inversions = 0;
    int i = l;
    int j = mid+1;
    int k = l;
    while(i <= mid && j <= r){
            cout << "comparing " << numbers[i] << " and " << numbers[j] << endl;
        if(numbers[i] <= numbers[j]){
            temp[k] = numbers[i];
            i++;
            k++;
        }
        else{

            temp[k] = numbers[j];
            for(int a = i; a < mid + 1; a++){
                cout << "checking the next elements: " << numbers[a] << "  and  " << numbers[j] << endl;
                if(numbers[j] * 2 < numbers[a]){
                    cout << "adding " << endl;
                    inversions +=1;
                }
            }

            j++;
            k++;
//            cout << "printing after adding:" << endl;
//            printV(temp, 0, temp.size()-1);
        }

    }
    while(i <= mid){
//            cout << "unfinished first subarray" <<endl;
//            cout << "k is: " << k << endl;
        temp[k] = numbers[i];
        i++;
        k++;
    }
    while(j <= r){
//            cout << "unfinished second subarray" <<endl;
        temp[k] = numbers[j];
        j++;
        k++;
    }
    for(int a = l; a <= r; a++){
        numbers[a] = temp[a];
    }
//    cout << "temp at the end: "<< endl;
//    printV(temp, 0, temp.size()-1);
//    cout << endl;
    return inversions;
}

long long inversions(int l, int r){
//    cout << "inside inversions with left: " << l << "  right: " << r << "  mid: " << (l + r)/2 << endl;
    if(r > l){
        int mid = (l + r)/2;
        long long first = inversions(l, mid);
//       cout << "done with first with left: " << l << "  right: " << r << "  mid: " << (l + r)/2 << endl;
        long long second = inversions(mid+1, r);
//       cout << "done with second" << endl;
        return first + second + merge(l, r, mid);
    }
    return 0;
}

int main(){
    int n;
    cin >> n;
    numbers.resize(n+4);
    temp.resize(n+4);
    for(int i = 0; i < n; i++){
        cin >> numbers[i];

    }
//    cout << "done getting input" << endl;
    cout << inversions(0, n-1) + 1  ;
}
