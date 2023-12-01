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
Node* deleteHead(Node* head) {
    if(head == NULL || head->next == NULL)
        return NULL;

    Node *temp = head;
    head = head->next;
    head->back = nullptr;
    temp->next = nullptr;

    free(temp);
    return head;
}

Node* deleteTail(Node* head) {
    // if(head == NULL) {
    //     return NULL;
    // }
    // Node* mover = head;
    // while(mover->next->next != NULL) {
    //     mover = mover->next;
    // }

    // Node *temp = mover->next;

    // mover->next = nullptr;
    // temp->back = nullptr;

    // free(temp);
    // return head;

        // or

    if(head == NULL || head->next == NULL) {
        return NULL;
    }

    Node *tail = head;

    while(tail->next != NULL) {
        tail = tail->next;
    }

    Node *newTail = tail->back;
    newTail->next = nullptr;
    tail->back = nullptr;

    free(tail);

    return head;

}

Node *deleteAtKthPosition(Node* head, int k) {

    if(head == NULL) {
        return NULL;
    }

    int cnt = 0;
    Node *temp = head;
    Node *prev = nullptr;
    Node *front = nullptr;
    while(temp != NULL) {
        cnt++;
        if(cnt == k) {
            prev = temp->back;
            front = temp->next;
            break;
        }
        temp = temp->next;
    }

    if(prev == NULL && front == NULL) {
        return NULL;
    }
    else if(prev == NULL) {
        head = deleteHead(head);
        return head;
    }
    else if(front == NULL) {
        head = deleteTail(head);
        return head;
    }

    prev->next = front;
    front->back = prev;

    temp->back = nullptr;
    temp->next = nullptr;

    free(temp);
    return head;
}

void deleteNode(Node* temp) {
    Node* prev = temp->back;
    Node* front = temp->next;

    if(front == NULL) {
        prev->next = nullptr;
        temp->back = nullptr;

        free(temp);
    }

    prev->next = front;
    front->back = prev;

    temp->next = temp->back = nullptr;
    free(temp);
}

Node* insertAtHead(Node *head, int val) {
    if(head == NULL) return new Node(val);

    Node* newNode = new Node(val, head, nullptr);

    head->back = newNode;

    return newNode;
}

Node* insertBeforeTail(Node *head, int val) {
    if(head == NULL) return new Node(val);
    if(head->next == NULL) return insertAtHead(head, val);

    Node *tail = head;
    Node *prev = nullptr;
    Node *front = nullptr;
    while(tail->next != NULL) {
        tail = tail->next;
        prev = tail->back;
    }

    Node *newNode = new Node(val, tail, prev);

    tail->back = newNode;
    prev->next = newNode;

    return head;

}

Node *insertBeforeKthNode(Node *head, int val, int k) {
    if(k == 1){
        return insertAtHead(head, val);
    }

    int cnt = 0;
    Node *mover = head;
    while(mover != NULL) {
        cnt++;
        if(cnt == k) {
            break;
        }
        mover = mover->next;
    }

    Node *prev = mover->back;
    Node *newNode = new Node(val, mover, prev);
    prev->next = newNode;
    mover->back = newNode;
    return head;
}

void insertBeforeGivenNode(Node *node, int val) {
    Node *prev = node->back;

    Node *newNode = new Node(val, node, prev);
    prev->next = newNode;
    node->back = newNode;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80, 90};

    Node *head = convertToDLL(arr);

    traversal(head);

    head = deleteHead(head);
    traversal(head);

    head = deleteTail(head);
    traversal(head);

    head = deleteAtKthPosition(head, 5);
    traversal(head);

    deleteNode(head->next->next);
    traversal(head);

    head = insertAtHead(head, 10);
    traversal(head);

    head = insertBeforeTail(head, 75);
    traversal(head);

    head = insertBeforeKthNode(head, 25, 3);
    traversal(head);

    insertBeforeGivenNode(head->next->next, 15);
    traversal(head);
}