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
Node *middleOfLL(Node *head) {
    Node *fast = head;
    Node *slow = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node *head = convertToLL(arr);
    Node *middle = middleOfLL(head);
    traversal(middle);
}