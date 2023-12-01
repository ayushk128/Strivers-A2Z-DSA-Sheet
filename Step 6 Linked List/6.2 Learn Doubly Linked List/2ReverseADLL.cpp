#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;

    Node(int val)
    {
        data = val;
        next = nullptr;
        back = nullptr;
    }
    Node(int val, Node *next1, Node *back1)
    {
        data = val;
        next = next1;
        back = back1;
    }
};

void traversal(Node *head) {
    Node* mover = head;
    while(mover) {
        cout << mover->data << " ";
        mover = mover->next;
    }

    cout << endl;
}
Node *convertToDLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }

    return head;
}

Node *reverseDLL(Node *head) {
    if(head == NULL || head->next == NULL) return head;
    Node *current = head;
    Node *last = nullptr;
    while(current != NULL) {
        last = current->back;
        current->back = current->next;
        current->next = last;

        current = current->back;
    }

    head = last->back;
    return head;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80, 90};

    Node *head = convertToDLL(arr);

    traversal(head);

    head = reverseDLL(head);
    traversal(head);

}