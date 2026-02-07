#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

// Return node back to AVAIL list
void freeNode(Node *&AVAIL, Node *node)
{
    node->next = AVAIL;
    AVAIL = node;
}

// Delete the last node and return it to AVAIL
void deleteLast(Node *&START, Node *&AVAIL)
{
    // Step 1 : Check if list is empty
    if (START == NULL)
    {
        cout << "UNDERFLOW" << endl;
        return;
    }

    // Case 1 : Only one node in the list
    if (START->next == NULL)
    {
        Node *PTR = START;
        START = START->next;
        freeNode(AVAIL, PTR); // return to AVAIL
        return;
    }

    // Case 2: More than one node
    Node *PTR = START;
    Node *PREPTR = NULL;

    // Traverse until PTR points to the last node
    while (PTR->next != NULL)
    {
        PREPTR = PTR;    // Step 4
        PTR = PTR->next; // Step 5
    }

    // Disconnect last node
    PREPTR->next = NULL; // Step 6

    // Return last node to AVAIL instead of deleting
    freeNode(AVAIL, PTR); // Step 7
}

// Function to display linked list
void display(Node *start)
{
    Node *temp = start;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Initialize AVAIL with free nodes
Node *initializeAvail(int n)
{
    Node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        Node *temp = new Node;
        temp->next = head;
        head = temp;
    }
    return head;
}

int main()
{
    Node *AVAIL = initializeAvail(10); // free pool
    Node *START = NULL;

    // Build a list manually using AVAIL: 10 ->2- ->30->40
    Node *n1 = AVAIL;
    AVAIL = AVAIL->next;
    n1->data = 10;

    Node *n2 = AVAIL;
    AVAIL = AVAIL->next;
    n2->data = 20;

    Node *n3 = AVAIL;
    AVAIL = AVAIL->next;
    n3->data = 30;

    Node *n4 = AVAIL;
    AVAIL = AVAIL->next;
    n4->data = 40;

    n1->next = n2;

    n2->next = n3;

    n3->next = n4;

    n4->next = NULL;

    START = n1;

    cout << "Original List: ";
    display(START);

    // Delete last node
    deleteLast(START, AVAIL);
    cout << "After deleting last node: ";
    display(START);

    // Delete again
    deleteLast(START, AVAIL);
    cout << "After deleting again: ";
    display(START);

    // Delete until empty
    deleteLast(START, AVAIL);
    deleteLast(START, AVAIL);

    cout << "After deleting all nodes: ";
    display(START);

    // Try deleting from empty list
    deleteLast(START, AVAIL);
    return 0;
}