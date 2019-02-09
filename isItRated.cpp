#include <iostream>

using namespace std;

typedef struct participant participant;

struct participant{
    int first;
    int second;
};

int main(){
    int n;
    cin >> n;
    participant participants[n];
    for(int i = 0; i < n; i++){
        cin >> participants[i].first >> participants[i].second;
        if(participants[i].first != participants[i].second){
            cout << "rated";
            return 0;
        }
    }
    for(int i = 0; i < n-1; i++){
        if(participants[i].first < participants[i+1].first){
            cout << "unrated";
            return 0;
        }
    }
    cout << "maybe";
    return 0;

}
