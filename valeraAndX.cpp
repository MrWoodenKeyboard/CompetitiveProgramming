#include <iostream>

using namespace std;

bool isDiagonal(char **arr, int len){//I USED POINTER ARITHMETIC ARE YOU PROUD OF ME PAPA?
    char mainLetter = **arr;
    for(int i = 0; i < len; i++){
         if( ( *(*(arr+i)+i) == mainLetter && *(*(arr+i+1)-1-i) == mainLetter ) ){
            return false;
         }
    }
    return true;
}

bool twoLetters(char **arr, int len){
    char letter1 = **arr, letter2 = **arr;
    int flag = 1;
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++){
            if(arr[i][j] != letter1 && flag == 1){
                letter2 = arr[i][j];
                flag = 0;
            }
            else if(arr[i][j] != letter1 && arr[i][j] != letter2){
                return false;
            }
        }
    }
    return true;
}

bool onlyDiagonal(char **arr, int len){
    char mainLetter = **arr;
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++){
            if((j != len-1-i && j != i) && arr[i][j] == mainLetter){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int len, finish = 0;
    cin >> len;
    char paper[len][len];
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++){
            cin >> paper[i][j];
        }
    }
    char mainLetter = **paper;

    //onlyDiagonal
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++){
            if((j != len-1-i && j != i) && paper[i][j] == mainLetter){
                finish = 1;
//                cout << "onlyDiagonal\n";
            }
        }
    }

    //onlyTwoLetters
    char letter1 = **paper, letter2 = **paper;
    int flag = 1;
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++){
            if(paper[i][j] != letter1 && flag == 1){
                letter2 = paper[i][j];
                flag = 0;
            }
            else if(paper[i][j] != letter1 && paper[i][j] != letter2){
                finish = 1;
//                cout << "onlyTwoLetters\n";
            }
        }
    }

    //isDiagonal
    for(int i = 0; i < len; i++){
         if( !( *(*(paper+i)+i) == mainLetter && *(*(paper+i+1)-1-i) == mainLetter ) ){
//                cout << i << "  " << *(*(paper+i)+i) << "  " << *(*(paper+i+1)-1-i) << endl;
                finish = 1;
//                cout << "isDiagonal\n";
         }
    }

    if(finish == 1){
        cout << "NO";
    }
    else{
        cout << "YES";
    }

}
