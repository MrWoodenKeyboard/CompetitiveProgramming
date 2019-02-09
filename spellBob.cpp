//VERY LONG AND STUPID CODE. COULD BE DONE IN LIKE 10 LINES FUCK ME

#include <iostream>

using namespace std;

typedef struct card card;

struct card{
    char top;
    char bottom;
    int type;
};

void findType(card *card){
    if((card->top == 'b' && card->bottom == 'o') || (card->top == 'o' && card->bottom == 'b')){
        card->type = 3;
        return;
    }
    if((card->top == 'b' && card->bottom != 'o') || (card->bottom == 'b' && card->top != 'o')){
        card->type = 1;
        return;
    }
    if((card->top == 'o' && card->bottom != 'b') || (card->bottom == 'o' && card->top != 'b')){
        card->type = 2;
        return;
    }
    card->type = 0;
    return;
}

void isPossible(card *card1, card *card2, card *card3){
    if(card1->type == 0 || card2->type == 0 || card3->type == 0){
        cout << "no" << "\n";
        return;
    }
    int numberOne = 0, numberTwo = 0, numberThree = 0;
//      finding what types we have and how many
    //FIRST CARD
    if(card1->type == 1){
        numberOne++;
    }
    else if(card1->type == 2){
        numberTwo++;
    }
    else if(card1->type == 3){
        numberThree++;
    }
    //SECOND CARD
    if(card2->type == 1){
        numberOne++;
    }
    else if(card2->type == 2){
        numberTwo++;
    }
    else if(card2->type == 3){
        numberThree++;
    }
    //THIRD CARD
    if(card3->type == 1){
        numberOne++;
    }
    else if(card3->type == 2){
        numberTwo++;
    }
    else if(card3->type == 3){
        numberThree++;
    }
    //CHECK IF BOB CAN BE WRITTEN
    if((numberOne == 2 && numberTwo == 1) || (numberOne == 2 && numberThree == 1) || (numberOne == 1 && numberTwo == 1 && numberThree == 1) || (numberOne == 1 && numberThree == 2) || (numberTwo == 1 && numberThree == 2) || (numberThree == 3)){
        cout << "yes" << "\n";
    }
    else{
        cout << "no" << "\n";
    }
}


int main(){
    int t;
    cin >> t;
    card card1, card2, card3;
    string temp;
    for(int i = 0; i < t; i++){
        cin >> temp;
        card1.top = temp.at(0);
        card2.top = temp.at(1);
        card3.top = temp.at(2);
        cin >> temp;
        card1.bottom = temp.at(0);
        card2.bottom = temp.at(1);
        card3.bottom = temp.at(2);
        findType(&card1);
//        cout << "type of the first card is: " << card1.type << "\n";
        findType(&card2);
//        cout << "type of the second card is: " << card2.type << "\n";
        findType(&card3);
//        cout << "type of the third card is: " << card3.type << "\n";
        isPossible(&card1, &card2, &card3);
//        cout << "\n";
    }
}
