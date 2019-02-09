#include <iostream>
#include <string>
using namespace std;

int howManyFaces(string polyhedron){
    if(polyhedron == "Tetrahedron"){
        return 4;
    }
    else if(polyhedron == "Cube"){
        return 6;
    }
    else if(polyhedron == "Octahedron"){
        return 8;
    }
    else if(polyhedron == "Dodecahedron"){
        return 12;
    }
    else{
        return 20;
    }
}

int main(){
    int n, faces = 0;
    cin >> n;
    string temp;
    for(int i = 0; i < n; i++){
        cin >> temp;
        faces += howManyFaces(temp);
    }
    cout << faces;
}
