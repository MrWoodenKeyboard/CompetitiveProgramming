#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int> > dp;
int maxVal = -1;
int maxIndex = -1;

void longestCommonSubstring(string s1, string s2){
    for(int i1 = 0; i1 < s1.length(); i1++){
        for(int i2 = 0; i2 < s2.length(); i2++){
                cout << "inside with: " << i1 << "  " << i2 << endl;
            if(i1 == 0 || i2 == 0){
                continue;
            }
            if(s1.at(i1) == s2.at(i2)){
                cout << "found same" << endl;
                dp[i1][i2] = 1 + dp[i1-1][i2-1];
                if(dp[i1][i2] > maxVal){
                    maxVal = dp[i1][i2];
                    maxIndex = i1;
                }
            }
        }
    }
}

int main(){
    string s1 = "1ahm41e1aati";
    string s2 = "1me1aatin";
    //strings are treated as 1 indexed so you have to ,insert some arbitrary char in the beginning
    dp.resize(s1.length()+1, vector<int>(s2.length()+1));
    for(int i = 0; i < s1.length()+1; i++){
        for(int j = 0; j < s2.length()+1; j++){
            dp[i][j] = 0;
        }
    }
    longestCommonSubstring(s1, s2);
    for(int i = maxIndex - maxVal+1; i < maxIndex+1; i++){
        cout << s1.at(i);
    }
    cout << endl;
    for(int i = 0; i < s1.length()+1; i++){
        for(int j = 0; j < s2.length()+1; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}
