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
int length(Node *head) {
    Node *temp = head;
    temp = head;
    int len = 0;
    while(temp) {
        temp=temp->next;
        len++;
    }
    return len;
}
bool searchInLL(Node *head, int val) {
    Node *temp = head;
    while(temp) {
        if(temp->data == val)
            return true;
        temp = temp->next;
    }
    return false;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> arr = {2, 4, 6, 10, 8};

    Node *head = convertToLL(arr);
    cout << head->data << endl;

    // Traversal
    traversal(head);
    cout << length(head) << endl;
    cout << searchInLL(head, 50) << endl;
}