#include <iostream>

using namespace std;

struct node{
    int data;
    node *l;
    node *r;
};

typedef struct node node;

node* createNode(int val){
    node *temp = (node*) malloc(sizeof(node));
    temp->data = val;
    temp->l = NULL;
    temp->r = NULL;
    return temp;
}

void printBST(node* root){
    if(root == NULL){
        return;
    }
    printBST(root->l);
    cout << root->data << endl;
    printBST(root->r);
}

node* insertVal(node* root, int val){
    if(root == NULL){
        root = createNode(val);
        return root;
    }
    if(root->data > val){
        root->l = insertVal(root->l, val);
        return root;
    }
    else{
        root->r = insertVal(root->r, val);
        return root;
    }
}

int LCA(node* root, int a, int b){
    if(root->data < a && root->data < b){
        return LCA(root->r, a, b);
    }
    else if(root->data > a && root->data > b){
        return LCA(root->l, a, b);
    }
    else{
        return root->data;
    }
}

int main(){
    int n, q;
    cin >> n >> q;
    int temp;
    node *root = NULL;
    for(int i = 0; i < n; i++){
        cin >> temp;
        root = insertVal(root, temp);
    }
//    cout << "finished inputting" << endl;
//    printBST(root);
    int a, b;
    for(int i = 0; i < q; i++){
        cin >> a >> b;
        cout << LCA(root, a, b) << endl;
    }
}
