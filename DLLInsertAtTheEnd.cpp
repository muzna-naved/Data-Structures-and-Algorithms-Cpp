// insert at the end
#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *prev;
    Node *next;
};

// Display list in forward direction
void displayForward(Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

// Create AVAIL list
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

// Insert a new node at the end
void insertAtEnd(Node *&START, Node *&AVAIL, int val)
{
    // Step 1: If AVAIL is NULL, no free node is available
    if (AVAIL == NULL)
    {
        cout << "OVERFLOW" << endl;
        return;
    }

    // Step 2: Take first free node from AVAIL
    Node *New_Node = AVAIL;

    // Step 3: Move AVAIL to next free node
    AVAIL = AVAIL->next;

    // Step 4: Store value in New_Node
    New_Node->data = val;

    // Step 5: Since this is last node, NEXT will be NULL
    New_Node->next = NULL;

    // Step 6: If list is empty
    if (START == NULL)
    {
        New_Node->prev = NULL;   // No previous node
        START = New_Node;        // New node becomes first node
        return;
    }

    // Step 7: Start traversal from first node
    Node *PTR = START;

    // Step 8 & 9: Move PTR until last node is found
    while (PTR->next != NULL)
    {
        PTR = PTR->next;
    }

    // Step 10: Link last node with new node
    PTR->next = New_Node;

    // Step 11: Set previous of new node
    New_Node->prev = PTR;

    // Step 12: Exit function
}

int main()
{
    Node *START = NULL;

    // Create AVAIL list with 5 free nodes
    Node *AVAIL = initializeAvail(5);

    insertAtEnd(START, AVAIL, 10);
    insertAtEnd(START, AVAIL, 20);
    insertAtEnd(START, AVAIL, 30);

    displayForward(START);

    return 0;
}
