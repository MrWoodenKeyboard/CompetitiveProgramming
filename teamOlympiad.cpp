#include <iostream>
#include <algorithm>
using namespace std;

int findFirst(int arr[], int len, int n){
    int i = 0;
    for(; arr[i] != n && i < len; i++){}
    return i;
}

int findNumberAfter(int arr[], int n, int index){
    int i = index;
    for(; arr[i] != n; i++){};
    return i;
}

void printArr(int arr[], int len){
    for(int i = 0; i < len; i++){
        cout << arr[i] << "\t";
    }
    cout << "\n";
}

int maximum(int a, int b, int c){
   int max = ( a < b ) ? b : a;
   return ( ( max < c ) ? c : max );
}

int main(){
    int n, flag = 0;
    cin >> n;
    int students[n], sortedStudents[n];
    for(int i = 0; i < n; i++){
        cin >> students[i];
        sortedStudents[i] = students[i];

    }
    sort(sortedStudents, sortedStudents+n);
//    printArr(students, n);
    int iProg, iMath, iPe, numProg, numMath, numPe, teams;
    iProg = 0;
    iMath = findFirst(sortedStudents, n, 2);
    iPe = findFirst(sortedStudents, n, 3);
//    cout << "iProg: " << iProg << " iMath: " << iMath << " iPe: " << iPe << endl;
    numProg = iMath;
    numMath = iPe - iMath;
    numPe = n - iPe;
    if(numProg <= 0 || numMath <= 0 || numPe <= 0){
        cout << 0;
        return 0;
    }
//    cout << "numProg: " << numProg << " numMath: " << numMath << " numPe: " << numPe << endl;
    teams = min(numProg,min(numMath,numPe));
    cout << teams << endl;
    iProg = 0;
    iMath = 0;
    iPe = 0;
    for(int i = 0; i < teams; i++){
        if(i == 0){
            iProg = findNumberAfter(students, 1, 0);
            iMath = findNumberAfter(students, 2, 0);
            iPe = findNumberAfter(students, 3, 0);
        }
        else{
            iProg = findNumberAfter(students, 1, iProg+1);
            iMath = findNumberAfter(students, 2, iMath+1);
            iPe = findNumberAfter(students, 3, iPe+1);
        }

        cout << iProg + 1 << " " << iMath + 1 << " " << iPe + 1<< endl;
    }
}
