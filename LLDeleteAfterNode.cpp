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

// Delete a node with value NUM and return it to AVAIL
void deleteNode(Node *&START, Node *&AVAIL, int NUM)
{
    // Step 1 : Check if list is empty
    if (START == NULL)
    {
        cout << "UNDERFLOW" << endl;
        return;
    }

    // Case 1 : First node contains NUM
    if (START->data == NUM)
    {
        Node *PTR = START;
        START = START->next;
        freeNode(AVAIL, PTR); // return to AVAIL
        return;
    }

    // Case 2: Search for NUM
    Node *PTR = START;
    Node *PREPTR = NULL;

    // Traverse until PTR points to the last node
    while (PTR != NULL && PTR->data != NUM)
    {
        PREPTR = PTR;    // Step 4
        PTR = PTR->next; // Step 5
    }

    if (PTR == NULL)
    {
        cout << "VALUE NOT FOUND" << endl;
        return;
    }

    // Disconnect last node
    PREPTR->next = PTR->next; // Step 6

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
    deleteNode(START, AVAIL, 30);
    cout << "After deleting 30: ";
    display(START);

    deleteNode(START, AVAIL, 10);
    cout << "After deleting 10: ";
    display(START);

    deleteNode(START, AVAIL, 99);
    deleteNode(START, AVAIL, 40);

    cout << "After deleting 40: ";
    display(START);

    deleteNode(START, AVAIL, 20);
    cout << "FINAL LIST: ";
    display(START);

    deleteNode(START, AVAIL, 5); // UNDERFLOW

    return 0;
}