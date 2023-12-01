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
Node *addTwoNumbers(Node *head1, Node *head2) {
    Node *t1 = head1;
    Node *t2 = head2;
    Node *dummyNode = new Node(-1);
    Node *curr = dummyNode;

    int carry = 0;
    int sum = 0;
    while(t1 != NULL || t2 != NULL) {
        sum = carry;

        if(t1) sum += t1->data;
        if(t2) sum += t2->data;

        Node *newNode = new Node(sum % 10);
        curr->next = newNode;
        curr = curr->next;
        carry = sum / 10;

        if(t1) t1 = t1->next;
        if(t2) t2 = t2->next;

    }

    if(carry) {
        Node *newNode = new Node(carry);
        curr->next = newNode;
        curr = curr->next;
    }

    return dummyNode->next;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> arr1 = {2, 4, 3};
    Node *head1 = convertToLL(arr1);

    vector<int> arr2 = {5, 6, 4};
    Node *head2 = convertToLL(arr2);

    Node *sumList = addTwoNumbers(head1, head2);

    traversal(sumList);

}