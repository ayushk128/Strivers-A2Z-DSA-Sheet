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

Node* sortList(Node *head){
    if(head == NULL || head->next == NULL) return head;
    
    Node* dummyZero = new Node(-1);
    Node* dummyOne = new Node(-1);
    Node* dummyTwo = new Node(-1);

    Node* moverZero = dummyZero;
    Node* moverOne = dummyOne;
    Node* moverTwo = dummyTwo;

    Node* temp = head;

    while(temp != NULL) {
        if(temp->data == 0) {
            moverZero->next = temp;
            moverZero = temp;
            
        }

        else if(temp->data == 1) {
            moverOne->next = temp;
            moverOne = temp;
        }
        else {
            moverTwo->next = temp;
            moverTwo = temp;
        }

        temp = temp->next;
    }

    
    moverZero->next = (dummyOne->next) ? (dummyOne->next) : dummyTwo->next;
    moverOne->next = (dummyTwo->next);
    moverTwo->next = nullptr;

    Node* newHead = dummyZero->next;

    delete dummyZero;
    delete dummyOne;
    delete dummyTwo;
    
    return newHead;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> arr = {1, 0, 2, 1, 0, 2, 1};
    Node *head = convertToLL(arr);
    traversal(head);

    head = sortList(head);
    traversal(head);
    

}