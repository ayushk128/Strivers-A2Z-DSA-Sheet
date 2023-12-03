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

Node *removeNode(Node *head, int n) {
    if(head == NULL) return NULL;
    Node *fast = head;
    Node *slow = head;

    int k = n;
    while(k) {
        fast = fast->next;
        k--;
    }

    if(fast == NULL) {
        Node *newHead = head->next;
        free(head);
        return newHead;

    }
    while(fast->next) {
        fast = fast->next;
        slow = slow->next;
    }

    Node *delNode = slow->next;
    slow->next = slow->next->next;

    free(delNode);

    return head;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> arr = {1, 2, 3, 4, 5};
    int n = 2;
    Node *head = convertToLL(arr);
    head = removeNode(head, 2);
    traversal(head);
}