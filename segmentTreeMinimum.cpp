#include <iostream>

using namespace std;

void printArr(int n, int arr[]){
    for(int i = 0; i < n; i++){
        cout << "element " << i << "is: " << arr[i] << endl;
    }
    cout << endl;
    return;
}

void build(int st[], int arr[], int start, int end, int node){
    if(start == end){
        st[node] = arr[start];
    }
    else{
        int mid = (start + end)/2;
        build(st, arr, start, mid, node*2);
        build(st, arr, mid + 1, end, node*2 + 1);
        st[node] = min(st[node*2], st[node*2 + 1]);
    }
}

void update(int st[], int arr[], int index, int start, int end, int node, int val){
    if( end == start ){
        arr[start] = val;
        st[node] = val;
    }
    else{
        int mid = (start + end)/2;
        if(index <= mid && index >= start){
            update(st, arr, index, start, mid, node*2, val);
            st[node] = min(st[node*2], st[node*2 + 1]);
        }
        else{
            update(st, arr, index, mid+1, end, node*2 + 1, val);
            st[node] = min(st[node*2], st[node*2 + 1]);
        }
    }
}

int minVal(int st[], int start, int end, int left, int right, int node){
    if( left <= start && right >= end ){
        return st[node];
    }

    else if( start > right || end < left ){
        return 100000;
    }

    else{
        int mid = (start + end)/2;
        int val = min( minVal(st, start, mid, left, right, node*2), minVal(st, mid+1, end, left, right, node*2 + 1) );
        return val;
    }
}

int main(){
    int arr[] = {1, 3, 2, 5, 4, 7, 8};
    int len = sizeof(arr)/sizeof(arr[0]);
    int st[len*4];
    build(st, arr, 0, len-1, 1);
    //printArr(len*4, st);
    int left = 0;
    int right = 6;
    cout << minVal(st, 0, len-1, left, right ,1) << endl;
    update(st, arr, 0, 0, len-1, 1, 20);
    cout << minVal(st, 0, len-1, left, right , 1) << endl;
    update(st, arr, 2, 0, len-1, 1, 30);
    cout << minVal(st, 0, len-1, left, right , 1) << endl;
}
