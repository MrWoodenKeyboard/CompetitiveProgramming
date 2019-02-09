#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string number){
    for(int i = 0, j = number.length() - 1; i < j; i++, j--){
        if(number.at(i) != number.at(j)){
            return false;
        }
    }
    return true;
}

string changeMiddle(string number){//ortasý 9 sa ya da 99sa bi çözüm bulman lazým o 9u ya da 9larý 0 yapýp ortadan birer adým uzaklaþým onlarý 1 artýrmayý düþünebilirsin onlar da 9sa sonraki basamaklar vb vb en sona gelirsen de artýk ilk basamaðý 1 yap son basamaðý 1 yap diðerleri zaten 0lanmýþ olacak
//    cout << "entered with:  " << number << endl;
    if(number.length()%2 == 1){
//        cout << "Length is odd number" << endl;
        char temp = number.at(number.length()/2);
        if(temp == '9'){
//            cout << "middle is 9" << endl;
            number.replace(number.length()/2, 1, "0");
            int i = (number.length()/2) - 1;
            int j = (number.length()/2) + 1;
            if(i == -1){
                return "11";
            }
            char temp1 = number.at(i);
            char temp2 = number.at(j);
//            cout << "before while loop: " << number << endl;
//            cout << "temp1: " << temp1 << "   temp2: " << temp2 << endl;
            while(temp1 == '9' && temp2 == '9'){
//                cout << "in while loop" << endl;
                number.replace(i, 1, "0");
                number.replace(j, 1, "0");
//                cout << "changed" << endl;

                i--;
                j++;
//                cout << "changed numbers" << endl;
//                cout << number << endl;
                if(i == -1){
//                    cout << "i is out of bound now" << endl;
                    number.insert(0, "1");
                    number.replace(number.length()-1, 1, "1");
                    return number;
                }
                else{
                    temp1 = number.at(i);
                    temp2 = number.at(j);
                }
//                cout << "temp1: " << temp1 << "   temp2: " << temp2 << endl;
            }
            if(temp1 == '9'){
                number.replace(j, 1, "9");
            }
            else if(temp2 == '9'){
                number.at(i)++;
                char temp[3];
                temp[0] = number.at(i)++;
                temp[1] = '\0';
                number.replace(j, 1, temp);
            }
            else{
                number.at(i)++;
                number.at(j)++;
            }
        }
        else{
            number.at(number.length()/2)++;   //bakalým çalýþacak mý
        }

    }
    else{
//        cout << "Length is even number" << endl;
        char temp = number.at(number.length()/2);
        int i = (number.length()/2) - 1;
        int j = number.length()/2;
        if(temp == '9'){//ÇALIÞMIYOR BU ÇALIÞMIYORSA ÜSTTEKÝ DE ÇALIÞMAZ
//            cout << "9s at the middle" << endl;
            temp = number.at(i);
//            cout << "i is:   " << i << "   j is:   " << j  << endl;
            while(temp == '9'){
//                cout << "number become: " << number << endl;
                number.replace(i, 1, "0");//bu iki satýr deðiþtirmiyor
                number.replace(j, 1, "0");
//                cout << "before      i is:  " << i << "  j is:  " << j << endl;
                i--;
                j++;
//                cout << "after      i is:  " << i << "  j is:  " << j << endl;
//                cout << "i is:   " << i << "   j is:   " << j  << endl;
                if(i == -1){//buralar çalýþmýyor
//                    cout << "i is now -1" << endl;
                    number.insert(0, "1");
                    number.replace(number.length()-1, 1, "1");
                    break;
                }
                temp = number.at(i);
//                cout << "temp is:  " << temp << endl;
//                cout << "smh" << endl;
            }
            if(i != -1){
                number.at(i)++;   //bakalým çalýþacak mý
                number.at(j)++;   //bakalým çalýþacak mý
            }

//            cout << "lol  " << number << endl;
        }
        else{
//            cout << "in else" << endl;
//            cout << "i is:  " << i << "  j is:  " << j << endl;
            number.at(i)++;   //bakalým çalýþacak mý
            number.at(j)++;   //bakalým çalýþacak mý
        }
    }
//    cout << "number before exit: " << number << endl;
    return number;
}

string palindromize(string number){
    string tempNumber = number;
    for(int i = 0, j = tempNumber.length() - 1; i < j; i++, j--){
        char temp[10];
        temp[0] = tempNumber.at(i);
        temp[1] = '\0';
        tempNumber.replace(j, 1, temp);
    }
//    cout << "before changeMiddle:  " << tempNumber << endl;
    if(tempNumber <= number){
        tempNumber = changeMiddle(tempNumber);
    }
//    cout << "palindromized version of the number:  " << tempNumber << endl;
    return tempNumber;
}

string nextPalindrome(string number){
/*
    if(number == "0" || number == "1" || number == "2" || number == "3" || number == "4" || number == "5" || number == "6" || number == "7" || number == "8" || number == "9"){
        return "11";
    }
*/
    if(isPalindrome(number)){
//        cout << "Number is palindrome " << endl;
        number = changeMiddle(number);
    }
    else{
//        cout << "Number is not palindrome " << endl;
        string tempNumber = number;
        tempNumber = palindromize(tempNumber);
        if(tempNumber.length() <= number.length() && tempNumber <= number){
//            cout << "in the if" << endl;
            tempNumber = changeMiddle(tempNumber);
        }
        number = tempNumber;
    }
    return number;
}

int main(){
    int t;
    string number;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> number;
        if(i != 0){
            cout << endl;
        }
        number = nextPalindrome(number);
        cout << number;
    }
}
/*

int main(){
    string number = "96978";
    cout << nextPalindrome(number);
}
*/
