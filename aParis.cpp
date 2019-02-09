#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<float> answers;// dont forget to erase all elements as soon as a better k is found
vector<int> points;


/*
int index, currItems, minItem;
float prevPoint;

float pointsGot(){
    int currItem = points[index];
    float currPoint = currItems*prevPoint;
    if(currItem < minItem){
        currPoint += minItem;
        minItem = currItem;
    }
    else{
        currPoint += currItem;
    }
    currItems++;
    currPoint /= currItems;
    return currPoint;
}
//check the variable names being used, s,mulate some cases on paper and try the code
void maxPoint(int n){
    currItems = 2;
    minItem = min(points[n-2], points[n-1]);

    prevPoint = (points[n-2] + points[n-1]) - minItem;
    float maxPoint = prevPoint;

    answers.push_back(n-2);
    float currPoint;
    for(int i = n-3; i >= 1; i--){//burda doðru yerden baþlayýp doðru yerde bitirdiðinden emin ol elinle kaðýtta iterasyon fln yap
        index = i;
        currPoint = pointsGot();
        if(currPoint > maxPoint){
            answers.clear();
            answers.push_back(i);
            maxPoint = currPoint;
        }
        else if(currPoint == maxPoint){
            answers.push_back(i);
        }
    }
}
*/

void printVector(vector <float> v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }
}

void maxPoint(int n){
    int currItems = 1;//one of the items is discarded as the minimum
    int minItem = min(points[n-2], points[n-1]);
    float currPoint = points[n-2] + points[n-1] - minItem;
    float prevPoint;
    float maxPoint = currPoint;
    answers.push_back(n-2);
    int currItem;
    for(int i = n-3; i > 0; i--){
        prevPoint = currPoint;
        currItem = points[i];

        currPoint = currPoint*currItems;
        if(currItem < minItem){
            currPoint = currPoint + minItem;
            minItem = currItem;
        }
        else{
            currPoint = currPoint + currItem;
        }
        currItems++;

        currPoint = currPoint/currItems;

        if(currPoint > maxPoint){
            answers.clear();
            answers.push_back(i);//acaba ne eklemeliyim tam emin değilim
            maxPoint = currPoint;
        }
        else if (currPoint == maxPoint){
            answers.push_back(i);
        }
    }
}

int main(){
    int n;
    cin >> n;
    int temp;
    for(int i = 0; i < n; i++){
        cin >> temp;
        points.push_back(temp);
    }
    maxPoint(n);
    sort(answers.begin(), answers.end());
    printVector(answers);
}
