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
int diameter(Node *root, int &dia) {
    if(root == NULL) return 0;
    int lh = diameter(root->left, dia);
    int rh = diameter(root->right, dia);

    dia = max(dia, lh + rh);
    return 1 + max(lh, rh);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Node *root = new Node(4);
    root->left = new Node(7);
    root->right = new Node(8);
    root->right->left = new Node(1);
    root->right->left->left = new Node(3);
    root->right->left->left->left = new Node(5);
    root->right->right = new Node(0);
    root->right->right->left = new Node(2);
    root->right->right->left->left = new Node(0);
    root->right->right->right = new Node(11);

    int dia = 0;
    diameter(root, dia);
    cout << dia << endl;
}