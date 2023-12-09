#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int num;
    Node *next;
    Node(int val)
    {
        num = val;
        next = NULL;
    }
};
// utility function to insert node at the end of the linked list
void insertNode(Node *&head, int val)
{
    Node *newNode = new Node(val);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return;
}
// utility function to check presence of intersection
Node *intersectionPoint(Node *head1, Node *head2) {
    Node *t1 = head1;
    Node *t2 = head2;

    while(t1 != t2) {
        t1 = t1->next;
        t2 = t2->next;

        if(t1 == t2) return t1;

        if(t1 == NULL) t1 = head2;
        if(t2 == NULL) t2 = head1;
    }
    return NULL;
}

// utility function to print linked list created
void printList(Node *head)
{
    while (head->next != NULL)
    {
        cout << head->num << "->";
        head = head->next;
    }
    cout << head->num << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Node *head = NULL;
    insertNode(head, 1);
    insertNode(head, 3);
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 4);

    Node *head1 = head;
    head = head->next->next->next;

    Node *headSec = NULL;
    insertNode(headSec, 3);
    Node *head2 = headSec;
    headSec->next = head;
    // printing of the lists
    cout << "List1: ";
    printList(head1);
    cout << "List2: ";
    printList(head2);

    // checking if intersection is present
    Node *answerNode = intersectionPoint(head1, head2);

    if (answerNode == NULL)
        cout << "No intersection\n";
    else
        cout << "The intersection point is " << answerNode->num << endl;
    return 0;
}