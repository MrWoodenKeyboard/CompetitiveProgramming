#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

void printVector(vector <int> v){
    for(int i = 0; i < v.size(); i++){
        cout << v.at(i) << " ";
    }
}

vector <int> factor(int n){
    vector <int> factors;
    for(int i = 2; i*i <= n; i++){
        if(n%i == 0){
            factors.push_back(i);
            if(n/i != i){
                factors.push_back(n/i);
            }
        }
    }
    factors.push_back(n);
    return factors;
}

int main(){
    int n;
    cin >> n;
    vector <int> numbers;
    int temp;
    for(int i = 0; i < n; i++){
        cin >> temp;
        numbers.push_back(temp);
    }
    int difference = abs(numbers[0] - numbers[1]);
    vector <int> factors = factor(difference);
    sort(factors.begin(), factors.end());
    vector <int> newFactors;
    vector <int> tempV;
    vector<int>::iterator ls;
    factors = factor(abs(numbers.at(1) - numbers.at(0)));
    cout << "factors in the beinning are: ";
    printVector(factors);
    cout << endl;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            difference = abs(numbers.at(i) - numbers.at(j));

            cout << "Difference is: " << difference << endl;

            newFactors = factor(difference);
            sort(newFactors.begin(), newFactors.end());

            cout << "factors of the difference are: ";
            printVector(newFactors);
            cout << endl;
            tempV.reserve(1000);
            ls = set_intersection(factors.begin(), factors.end(), newFactors.begin(), newFactors.end(), tempV.begin()); //problem var
            factors.clear();
            for(int i = 0; i < tempV.end() - tempV.begin(); i++){
                factors.push_back(tempV.at(i));
            }
            sort(factors.begin(), factors.end());
            tempV.clear();
            cout << "the intersection of the two vectors are: ";
            printVector(factors);
            cout << endl;

        }
    }
    printVector(factors);
}
