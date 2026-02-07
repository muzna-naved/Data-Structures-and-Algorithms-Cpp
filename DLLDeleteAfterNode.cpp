// Delete a node

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

// Delete the node AFTER a given node (NUM)
void deleteAfter(Node *&START, Node *&AVAIL, int NUM)
{
    // Step 1: IF START = NULL
    if (START == NULL)
    {
        cout << "UNDERFLOW" << endl;
        return;
    }

    // Step 2: SET PTR = START
    Node *PTR = START;

    // Step 3 & 4: Find node with DATA = NUM
    while (PTR != NULL && PTR->data != NUM)
    {
        PTR = PTR->next;
    }

    // If NUM not found
    if (PTR == NULL)
    {
        cout << "VALUE NOT FOUND" << endl;
        return;
    }

    // Step 5: SET TEMP = PTR->NEXT
    Node *TEMP = PTR->next;

    // Step 6: IF TEMP = NULL
    if (TEMP == NULL)
    {
        // No node after NUM
        return;
    }

    // Step 7: SET PTR->NEXT = TEMP->NEXT
    PTR->next = TEMP->next;

    // Step 8: IF TEMP->NEXT != NULL
    if (TEMP->next != NULL)
    {
        TEMP->next->prev = PTR;
    }

    // Step 9: FREE TEMP
    freeNode(AVAIL, TEMP);

    // Step 10: EXIT
}

int main()
{
    Node *AVAIL = initializeAvail(10); // free pool
    Node *START = NULL;

    // Take nodes from AVAIL
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

    // Delete last node
    deleteAfter(START, AVAIL, 30);
    cout << "After deleting 30: ";
    displayForward(START);

    deleteAfter(START, AVAIL, 10);
    cout << "After deleting 10: ";
    displayForward(START);

    deleteAfter(START, AVAIL, 99);
    deleteAfter(START, AVAIL, 40);

    cout << "After deleting 40: ";
    displayForward(START);

    deleteAfter(START, AVAIL, 20);
    cout << "FINAL LIST: ";
    displayForward(START);

    deleteAfter(START, AVAIL, 5); // UNDERFLOW
    return 0;
}
