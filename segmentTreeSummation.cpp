#include <iostream>

using namespace std;

void printArr(int arr[], int n){
    for(int i = 0; i < n;i ++){
        cout << "node " << i << ": " << arr[i] << endl;
    }
    cout << endl;
}

void build(int st[], int arr[], int node, int start, int end){
    cout << "inside with node: " << node << "  start: " << start << "  end: " << end << endl;
    if(start == end){
        cout << "at leaf node" << endl;
        st[node] = arr[start];
    }
    else{
        int mid = (start + end)/2;
        build(st, arr, 2*node, start, mid);
        build(st, arr, 2*node + 1, mid+1, end);
        st[node] = st[2*node] + st[2*node + 1];
    }
    return;
}

void update(int st[], int arr[], int val, int index, int node, int start, int end){
    if(start == end){
        arr[index] += val;
        st[node] += val;
    }
    else{
        int mid = (start + end)/2;
        if(index >= start && index <= mid){
            update(st, arr, val, index, node*2, start, mid);
        }
        else{
            update(st, arr, val, index, node*2 + 1, mid+1, end);
        }
        st[node] = st[node*2] + st[node*2 + 1];
    }
}

int query(int st[], int node, int start, int end, int l, int r){
    cout << "entered query with start: " << start << "  end: " << end << endl;
    if(r < start || l > end){
        cout << "completely out of bounds" << endl;
        return 0;
    }
    if( l <= start && r >= end){
        cout << "completeyly inside" << endl;
        return st[node];
    }
    else{
        cout << "half and half" << endl;
        int mid = (start + end)/2;
        int sum = query(st, node*2, start, mid, l, r) + query(st, node*2 + 1, mid + 1, end, l, r);
        return sum;
    }
}

int main(){

    int arr[] = { 1, 3, 5, 7, 9, 11 };
    int n = sizeof(arr)/sizeof(arr[0]);
    int st[4*n];
    build(st, arr, 1, 0, n-1);
    printArr(st, 4*n);
    cout << endl << query(st, 1, 0, n-1, 1, 3) << endl;
    update(st, arr, 10, 1, 1, 0, n-1);//update function doesn't update, it adds the number, solution is easy, find the difference between the new and current value, then add the difference to get tthe desired new value
    printArr(st, 4*n);
    cout << endl << query(st, 1, 0, n-1, 1, 3) << endl;
    /*
    int l = 0;
    int r = 6;
    cout << query(st, 1, 0, n, l, r);
    */
}
