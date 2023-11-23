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

void levelOrderTraversal(Node *node) {
    if(node == NULL) 
        return;

    queue<Node *> q;
    q.push(node);

    while(!q.empty()) {
        Node *currNode = q.front();
        q.pop();

        cout << currNode->data <<" ";

        if(currNode->left != NULL) q.push(currNode->left);
        if(currNode->right != NULL) q.push(currNode->right);
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
    root->left->right->left = new Node(6);
    root->right->left = new Node(7);
    root->right->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);

    levelOrderTraversal(root);

}
