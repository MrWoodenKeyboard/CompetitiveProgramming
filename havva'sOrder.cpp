#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct node node;

struct node{
    int value;
    vector <int> adj;
};

vector <node> createTree(int n){
//    cout << "entered createTree" << endl;
    vector <node> tree;
    node root;
    root.value = n;
    tree.push_back(root);
    return tree;
}

node findNode(int value, vector <node> tree){
    for(int i = 0; i < tree.size(); i++){
        if(tree.at(i).value == value){
            return tree.at(i);
        }
    }
    return tree.at(0);
}


vector <node> addNode(int from, int value, vector <node> tree){
//    cout << "entered addNode" << endl;
    node newNode;
    newNode.value = value;
    tree.push_back(newNode);
    node parentNode = findNode(from, tree);
    parentNode.adj.push_back(value);
    sort(parentNode.adj.begin(), parentNode.adj.end());
//    cout << "aye";
    return tree;
}

queue <node> preOrderQ(vector <node> tree, node current, queue <node> preOrder){

}

queue <node> postOrderQ(vector <node> tree, node current, queue <node> postOrder){

}

void havvasOrder(vector <node> tree, int rootValue){
    node root = findNode(rootValue, tree);
    queue <node> preOrder, postOrder;
    preOrder = preOrderQ(tree, root, preOrder);
    postOrder = postOrderQ(tree, root, postOrder);
    while(!postOrder.empty()){
        cout << postOrder.front().value * preOrder.front().value << " ";
        postOrder.pop();
        postOrder.pop();
    }
}


int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        int r;
        cin >> r;
        vector <node> tree;
        tree = createTree(r);
        int from, to;
        for(int i = 0; i < n-1; i++){
            scanf("%d", &from);
            scanf("%d", &to);
            tree = addNode(from, to, tree);
        }
    }

}
