#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <long long> elements;
int sizeOfElements;
vector <long long> gcds;

void printVector(vector <long long> v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
}

long long gcd(long long a, long long b){
    if(a == 0){
        return b;
    }
    if(b == 0){
        return a;
    }
    else{
        if(a < b){
            return gcd(b%a ,a);
        }
        else{
            return gcd(a%b ,b);
        }
    }
}

long long findGCD(vector <long long> v){
    long long result = v[0];
    for(long long i = 1; i < v.size(); i++){
        result = gcd(result, v[i]);
    }
    return result;
}

void generateCases(int index, vector <long long> currentElements){//maske the vector pass by reference
/*
    cout << "index: " << index << " elements vector size: " << sizeOfElements << endl;
    cout << "inside generate with vector" << endl;
    printVector(currentElements);
    cout << endl;
*/
    if(index == sizeOfElements){
            if( currentElements.size() > 1 ){//size t here
                gcds.push_back(findGCD(currentElements) );
            }
        return;
    }

    generateCases(index+1, currentElements);
//    cout << "now adding  " << elements[index] << endl;
    currentElements.push_back( elements[index] );
    generateCases(index+1, currentElements);
    currentElements.pop_back();//as it is a recursive function and we are passing the vector by reference, i should leave it with no change for the other recursive calls
}

int main(){
    int t;
    cin >> t;
    int n;
    for(int i = 0; i < t; i ++){

        cin >> n;
        long long temp;
        for(int j = 0; j < n; j++){
            cin >> temp;
            elements.push_back(temp);
        }
        sizeOfElements = static_cast<int>(elements.size() );

        vector <long long> currentElements;
        generateCases(0, currentElements);

        sort( gcds.begin(), gcds.end() );
        printVector(gcds);

        elements.clear();
        gcds.clear();
        currentElements.clear();

        if(i != t-1){
            cout << endl << "--" << endl;
        }

    }

}
