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
int height(Node *root) {
    if(root == NULL) return 0;
    int lh = height(root->left);
    int rh = height(root->right);

    return 1 + max(lh, rh);
}
bool isBalancedNaive(Node *root) {
    if(root == NULL) return true;

    int lh = height(root->left);
    int rh = height(root->right);

    if(abs(lh - rh) > 1) return false;

    bool leftCheck = isBalancedNaive(root->left);
    bool rightCheck = isBalancedNaive(root->right);

    if((leftCheck == false) || (rightCheck == false)) return false;

    return true;
}

int checkBalancedOptimal(Node *root) {
    if(root == NULL) return 0;

    int lh = checkBalancedOptimal(root->left);
    int rh = checkBalancedOptimal(root->right);

    if(lh == -1 || rh == -1) return -1;

    if(abs(lh - rh) > 1) return -1;

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
    root->right->left->right = new Node(5);
    root->right->right = new Node(0);

    if(isBalancedNaive(root)) cout << "Balanced" << endl;
    else cout << "Not Balanced" << endl;
}