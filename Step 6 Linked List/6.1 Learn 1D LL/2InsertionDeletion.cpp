#include<bits/stdc++.h>
using namespace std;
class Node {

    public:
    int data;
    Node *next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

void traversal(Node *head) {
    Node *temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

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

Node* deleteHead(Node *head) {
    if(head == NULL)
        return head;

    Node* temp = head;
    head = head->next;

    delete temp;
    return head;
}

Node* deleteTail(Node *head) {

    if(head == NULL || head->next == NULL) return NULL;
    Node *temp = head;

    while(temp->next->next != NULL) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;

    return head;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> arr = {2, 4, 6, 10, 8};

    Node *head = convertToLL(arr);
    traversal(head);

    head = deleteHead(head);
    traversal(head);

    head = deleteTail(head);
    cout << head->data << endl;

    traversal(head);
}