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

int maxDepth(Node *root) {
    if(root == NULL)
        return 0;

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return 1 + max(leftDepth, rightDepth);
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Node *root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(1);
    root->left->right = new Node(10);
    root->right->left = new Node(3);
    root->right->left->left = new Node(8);
    root->right->left->right = new Node(11);
    root->right->right = new Node(4);

    cout << maxDepth(root) << endl;

}
