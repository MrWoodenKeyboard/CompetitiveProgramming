#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct range{
    long long l;
    long long r;


};

bool operator <(range const &r1, range const &r2){
    return r1.l < r2.l;
}

typedef struct range range;

void printV(vector<range> v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i].l << "  ";
    }
    cout << endl;
}

bool binarySearch(vector <range> v, long long n){
    int mid = v.size()/2;
    int l = 0;
    int r = v.size() - 1;
    while(l < mid){
//            cout << "l is: " << l << "  r is: " << r << endl;
//            cout << "v[l] is: " << v[l].l << "  v[mid] is: " << v[mid].l << "  v[r] is: " << v[r].l << endl;
        if(n < v[mid].l ){
            r = mid - 1;
        }
        else if(n > v[mid].l ){
            l = mid + 1;
        }
        else{
            break;
        }
        mid = (l + r)/2;
    }
//    cout << "at the end: " << endl;
//    cout << "l is: " << l << "  r is: " << r << endl;
//    cout << v[l].l << "  " << v[l].r << endl;
//    cout << v[mid].l << "  " << v[mid].r << endl;
//    cout << v[r].l << "  " << v[r].r << endl;

    if( v[mid].l <= n && v[mid].r >= n ){
        return true;
    }
    return false;
}


int main(){
    int n, q;
    cin >> n >> q;
    vector <range> ranges;
    ranges.resize(n);
    for(int i = 0; i < n; i++){
        cin >> ranges[i].l;
        cin >> ranges[i].r;
    }
    sort(ranges.begin(), ranges.end());
//    printV(ranges);
    int a;
    int bas, son, mid;
    for(int i = 0; i < q; i++){
        cin >> a;
        bas = 0;
        son = n-1;
        mid = (bas+son)/2;
        while(bas < son){
//            cout << "l is: " << l << "  r is: " << r << endl;
//            cout << "v[l] is: " << v[l].l << "  v[mid] is: " << v[mid].l << "  v[r] is: " << v[r].l << endl;
            if(a < ranges[mid].l ){
                son = mid - 1;
            }
            else if(a > ranges[mid].r ){
                bas = mid + 1;
            }
            else{
                break;
            }
            mid = (bas + son)/2;
        }
        if(ranges[mid].l <= a && ranges[mid].r >= a){
            puts("Yes");
        }
        else{
            puts("No");
        }
    }

}
