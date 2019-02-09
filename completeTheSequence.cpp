#include <iostream>
#include <vector>
using namespace std;

bool allTheSame(vector <int> arr){
    if(arr.empty()){
        return false;
    }
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] != arr[i-1]){
            return false;
        }
    }
    return true;
}

void printVector(vector <int> vector){
    for(int i = 0; i < vector.size(); i++){
        cout << vector[i] << " ";
    }
    cout << endl;
}

void printVectorFrom(vector <int> vector, int position){
    for(int i = position; i < vector.size(); i++){
        cout << vector[i] << " ";
    }
    cout << endl;
}

void completeTheSequence(vector <int> sequence, int len){//1 eleman varken napçan?
//    cout << "in complete the sequence" << endl;
    vector <int> differences;
    vector <int> firsts;
    int theOnlyNumber;
    if(sequence.size() == 1){
        theOnlyNumber = sequence[0];
        for(int i = 0; i < len; i++){
            cout << theOnlyNumber << " ";
        }
        cout << endl;
        return;
    }
    int lenForEnd = sequence.size();
    firsts.push_back(sequence[0]);
//    cout << differences.empty() << endl;
//    cout << allTheSame(differences) << endl;
    differences = sequence;
//    cout << "printing difference" << endl;
//    printVector(differences);
    int beginningSize;
    if(allTheSame(differences)){
        theOnlyNumber = differences[0];
        for(int i = 0; i < len; i++){
            cout << theOnlyNumber << " ";
        }
        cout << endl;
        return;
    }
    for(int j = 0; !allTheSame(differences); j++){
//        cout << "in the first for" << endl;
        beginningSize = differences.size();
//        printVector(differences);
//        cout << "size of differences is:  " << differences.size() << endl;
        for(int i = 1; i < beginningSize; i++){
//            cout << "first number:  " << differences[i] << "  second number:  " << differences[i-1] << endl;
            differences.push_back(differences[i] - differences[i-1]);
//            cout << "differences[i]: " << differences[i - 1] << endl;
        }
//        printVector(differences);
        differences.erase(differences.begin(),differences.begin()+beginningSize);
//        printVector(differences);
        firsts.push_back(differences[0]);
    }
//    cout << "printing firsts:  ";
//    printVector(firsts);
    int length = sequence.size() + len;
//    cout << "desired length is:  " << length << endl;

    vector <int> current;
    int constant = differences[0];
//    cout << "constant is: " << constant << endl;
    differences.clear();
    for(int i = 0; i < length; i++){
        differences.push_back(constant);
    }
//    cout << "differences vector is now:  ";
//    printVector(differences);
//    cout << "firsts vector is now:  ";
//    printVector(firsts);
    int nextMember;
//    cout << "size of differences: " << differences.size() << endl;
    int sizeBefore = differences.size();
//    cout << "size of firsts: " << firsts.size() << endl;
    for(int i = firsts.size()-2; i >=0; i--){
//        cout << "at index: " << i << endl;
        if(i != firsts.size()-2 && i != firsts.size()-2){
            current.erase(current.begin(), current.begin() + sizeBefore);
        }
        current.push_back(firsts[i]);
//        cout << "current with only the first element:  ";
//        printVector(current);
        for(int j = 1; j < length; j++){
            nextMember = differences[j-1] + current[j-1];
            current.push_back(nextMember);
        }
//        printVector(current);
        differences = current;
    }
//        printVector(current);
        printVectorFrom(current, lenForEnd);
}


int main(){
    int t, s, c, temp;
    vector <int> sequence;
    cin >> t;
    for(int i = 0; i < t; i++){
//        cout << i << "th sequence" << endl;
        cin >> s;
        cin >> c;
        for(int j = 0; j < s; j++){
//          cout << j << "th number" << endl;
            cin >> temp;
            sequence.push_back(temp);
        }
        completeTheSequence(sequence, c);
        sequence.clear();
    }
}

/*
int main(){
    vector <int> sequence;
    sequence.push_back(1);
    sequence.push_back(2);
    sequence.push_back(4);
    sequence.push_back(7);
    sequence.push_back(11);
    sequence.push_back(16);
    sequence.push_back(22);
    sequence.push_back(29);
    completeTheSequence(sequence, 10);
}
*/
