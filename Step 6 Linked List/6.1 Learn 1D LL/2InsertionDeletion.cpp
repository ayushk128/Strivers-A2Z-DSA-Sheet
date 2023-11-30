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

    Node(int val, Node* next1) {
        data = val;
        next = next1;
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

// Length of a LL
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

// Deletion from head
Node* deleteHead(Node *head) {
    if(head == NULL)
        return head;

    Node* temp = head;
    head = head->next;

    delete temp;
    return head;
}

// Deletion from tail
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

// Delete from a position K
Node* deleteAtK(Node* head, int k) {
    if(head == NULL) return head;

    if(k == 1) {
        Node *temp = head;
        head = head->next;
        free(temp);

        return head;
    }

    int cnt = 0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL) {
        cnt++;
        if(cnt == k) {
            prev->next = prev->next->next;
            free(temp);
            break;
        }

        prev = temp;
        temp = temp->next;
    }
    return head;
}

// Delete a specific value node
Node* deleteValue(Node* head, int val) {
    if(head == NULL) return head;
    if(head->data == val) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }

    Node* temp = head;
    Node* prev = NULL;
    while(temp->data != val) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = prev->next->next;
    free(temp);

    return head;
}

// Insertion at Head
Node *insertAtHead(Node* head, int val) {
    Node* newNode = new Node(val, head);
    head = newNode;

    return head;
}
// Insertion at Tail
Node *insertAtTail(Node *head, int val) {
    if(head == NULL) {
        return new Node(val);
    }
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new Node(val);

    return head;
}

Node* insertAtKthPosition(Node* head, int k, int val) {
    if(head == NULL) {
        return new Node(val);
    }

    if(k == 1) {
        Node *temp = new Node(val, head);
        return temp;
    }

    Node *temp = head;
    int cnt = 0;
    while(temp != NULL) {
        cnt++;
        if(cnt == k - 1) {
            Node *newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }

        temp = temp->next;
    }
    return head;
}

Node* insertBeforeElementX(Node* head, int val, int x) {

    if(head == NULL) {
        return NULL;
    }

    if(head->data == x) {
        Node *temp = new Node(val, head);
        return temp;
    }

    Node *temp = head;

    while(temp->next != NULL) {
        if(temp->next->data == x) {
            Node *newNode = new Node(val, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> arr = {2, 4, 6, 10, 8, 15, 6, 40, 71};

    Node *head = convertToLL(arr);
    traversal(head);

    head = deleteHead(head);
    traversal(head);

    head = deleteTail(head);
    cout << head->data << endl;

    traversal(head);

    head = deleteAtK(head, 3);
    traversal(head);

    head = deleteAtK(head, 6);
    traversal(head);

    head = deleteAtK(head, 1);
    traversal(head);

    head = deleteValue(head, 8);
    traversal(head);

    head = insertAtHead(head, 55);
    traversal(head);

    head = insertAtTail(head, 101);
    traversal(head);

    head = insertAtKthPosition(head, 3, 106);
    traversal(head);

    head = insertBeforeElementX(head, 500, 15);
    traversal(head);
}