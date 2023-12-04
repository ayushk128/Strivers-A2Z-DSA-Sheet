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
Node *reverseLL(Node *head) {
    Node *temp = head;
    Node *prev = NULL;

    while(temp) {
        Node *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    Node *newHead = prev;
    return newHead;
}
bool isPalindrome(Node *head) {
    if(head == NULL || head->next == NULL) return true;
    Node *fast = head;
    Node *slow = head;

    while(fast->next->next != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    Node *newHead = reverseLL(slow->next);
    Node *first = head;
    Node *second = newHead;

    while(second) {
        if(first->data != second->data) {
            reverseLL(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }

    reverseLL(newHead);
    return true;
    
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> arr = {1, 2, 2, 1};
    Node *head = convertToLL(arr);

    if(isPalindrome(head)) {
        cout << "Palindrome" << endl;
    }
    else cout << "Not Palindrome" << endl;
}