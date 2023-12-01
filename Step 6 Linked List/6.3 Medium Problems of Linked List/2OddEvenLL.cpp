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

Node* oddEvenList(Node *head) {
    if(head == NULL || head->next == NULL) return head;
    Node* odd = head;
    Node* even = head->next;
    Node* evenStored = head->next;

    while(even != NULL && even->next != NULL) {
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }

    odd->next = evenStored;

    return head;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> arr = {1, 3, 5, 7, 8, 9, 0};

    Node *head = convertToLL(arr);

    traversal(head);

    head = oddEvenList(head);
    traversal(head);

}