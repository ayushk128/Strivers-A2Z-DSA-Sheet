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

Node *reverse(Node *head) {
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
Node *addOne(Node *head) {

    int carry = 1;
    head = reverse(head);
    Node *temp = head;

    while(temp) {
        temp->data = temp->data + carry;

        if(temp->data < 10) {
            carry = 0;
            break;
        }
        else {
            temp->data = 0;
            carry = 1;
        }

        temp = temp->next;
    }

    if(carry == 1) {
        Node *newNode = new Node(1);
        head = reverse(head);
        newNode->next = head;
        head = newNode;
    }

    head = reverse(head);
    return head;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> arr = {1, 5, 9};
    Node *head = convertToLL(arr);

    head = addOne(head);
    traversal(head);

}
