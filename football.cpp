#include <iostream>
#include <string>
using namespace std;

int main(){
    int n, score1 = 0, score2 = 0;
    cin >> n;
    string team1, team2, temp;
    cin >> team1;
    for(int i = 0; i < n; i++){
        if(i != 0){
            cin >> temp;
            if(temp != team1){
                team2 = temp;
                score2++;
            }
            else{
                score1++;
            }
        }
        else{
            score1++;
        }
    }
    if(score1 > score2){
        cout << team1;
        return 0;
    }
    cout << team2;
}
