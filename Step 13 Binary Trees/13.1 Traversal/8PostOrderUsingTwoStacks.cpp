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

vector<int> postOrderUsingTwoStack(Node *root) {
    stack<Node *> st1;
    stack<Node *> st2;
    vector<int> postOrder;

    st1.push(root);

    while(!st1.empty()) {
        Node * top = st1.top();
        st1.pop();
        st2.push(top);
        if(top->left != NULL) st1.push(top->left);
        if(top->right != NULL) st1.push(top->right);

    }

    while(!st2.empty()) {
        int data = st2.top()->data;
        postOrder.push_back(data);
        st2.pop();
    }
    return postOrder;

}
int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->left->right = new Node(7);
    root->right->left->right->right = new Node(8);

    vector<int> ans = postOrderUsingTwoStack(root);
    for(int i = 0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }

}
