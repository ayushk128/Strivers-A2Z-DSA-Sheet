#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

Node* convertToLL(vector<int> &arr) {
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for(int i = 1; i<arr.size(); i++) {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}
void traversal(Node *head) {
    Node *temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node *reverseALLIterative(Node *head) {
    Node *temp = head;
    Node *prev = NULL;

    while(temp) {
        Node *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    head = prev;
    return head;
}
Node* reverseALLRecursive(Node *head) {
    if(head == NULL || head->next == NULL) return head;

    Node *newHead = reverseALLRecursive(head->next);

    Node *front = head->next;
    front->next = head;
    head->next = NULL;

    return newHead;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> arr = {1, 2, 3, 4, 5};
    int n = 2;
    Node *head = convertToLL(arr);
    traversal(head);
    head = reverseALLIterative(head);
    traversal(head);

    head = reverseALLRecursive(head);
    traversal(head);
}