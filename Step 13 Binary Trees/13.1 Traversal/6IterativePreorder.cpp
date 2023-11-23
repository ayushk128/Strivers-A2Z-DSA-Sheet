#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void iterativePreorder(Node *node) {
    if(node == NULL) return;

    stack<Node *> s;
    s.push(node);

    while(!s.empty()) {
        Node * curNode = s.top();
        s.pop();

        cout << curNode->data <<" ";
        if(curNode->right != NULL) s.push(curNode->right);
        if(curNode->left != NULL) s.push(curNode->left); 
    }
}
int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);

    iterativePreorder(root);

}
