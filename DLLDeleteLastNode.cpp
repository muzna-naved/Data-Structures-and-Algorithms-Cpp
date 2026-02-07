// Delete last node

#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *prev;
    Node *next;
};

// Forward traversal
void displayForward(Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

// Initialize AVAIL list
Node *initializeAvail(int n)
{
    Node *AVAIL = NULL;
    for (int i = 0; i < n; i++)
    {
        Node *temp = new Node();
        temp->next = AVAIL;
        AVAIL = temp;
    }
    return AVAIL;
}

// FREE PTR → return node to AVAIL list
void freeNode(Node *&AVAIL, Node *node)
{
    node->next = AVAIL;
    node->prev = NULL;
    AVAIL = node;
}

// Delete the last node and return it to AVAIL
void deleteLast(Node *&START, Node *&AVAIL)
{
    // Step 1: IF START = NULL
    if (START == NULL)
    {
        cout << "UNDERFLOW" << endl;
        return;
    }

    // Step 2: SET PTR = START
    Node *PTR = START;

    // Step 3 & 4: Traverse till last node
    while (PTR->next != NULL)
    {
        PTR = PTR->next;
    }

    // Step 5: SET PREPTR = PTR->PREV
    Node *PREPTR = PTR->prev;

    // Step 6: SET PREPTR->NEXT = NULL
    if (PREPTR != NULL)
    {
        PREPTR->next = NULL;
    }
    else
    {
        // only one node case (implicit handling)
        START = NULL;
    }

    // Step 7: FREE PTR
    freeNode(AVAIL, PTR);

    // Step 8: EXIT
}

int main()
{
    Node *AVAIL = initializeAvail(10); // free pool
    Node *START = NULL;

    // Take nodes from AVAIL
    Node *n1 = AVAIL; AVAIL = AVAIL->next; n1->data = 10;
    Node *n2 = AVAIL; AVAIL = AVAIL->next; n2->data = 20;
    Node *n3 = AVAIL; AVAIL = AVAIL->next; n3->data = 30;
    Node *n4 = AVAIL; AVAIL = AVAIL->next; n4->data = 40;

    // Build doubly linked list
    n1->prev = NULL;
    n1->next = n2;

    n2->prev = n1;
    n2->next = n3;

    n3->prev = n2;
    n3->next = n4;

    n4->prev = n3;
    n4->next = NULL;

    START = n1;

    cout << "Original List: ";
    displayForward(START);

    deleteLast(START, AVAIL);
    cout << "After deleting last node: ";
    displayForward(START);

    deleteLast(START, AVAIL);
    cout << "After deleting again: ";
    displayForward(START);

    deleteLast(START, AVAIL);
    deleteLast(START, AVAIL);

    cout << "After deleting all nodes: ";
    displayForward(START);

    deleteLast(START, AVAIL); // UNDERFLOW
    return 0;
}
