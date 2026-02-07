// insert at the end using insert at position
#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *prev;
    Node *next;
};

// Function to get a node from AVAIL
Node *getNode(Node *&AVAIL)
{
    if (AVAIL == NULL)
    {
        cout << "OVERFLOW" << endl;
        return NULL;
    }
    Node *newNode = AVAIL;
    AVAIL = AVAIL->next; // move AVAIL forward
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

// Insert at a given position (including last position)
void insertAtPosition(Node *&START, Node *&AVAIL, int VAL, int POS)
{
    // Step 1: Take a free node from AVAIL
    Node *newNode = getNode(AVAIL);
    if (newNode == NULL)
        return;

    // Step 2: Store value in new node
    newNode->data = VAL;

    // Step 3: If inserting at position 1 (beginning)
    if (POS == 1)
    {
        newNode->next = START;
        if (START != NULL)
            START->prev = newNode;
        newNode->prev = NULL;
        START = newNode;
        return;
    }

    // Step 4: Traverse to (POS-1)th node
    Node *PTR = START;
    int count = 1;

    while (PTR != NULL && count < POS - 1)
    {
        PTR = PTR->next;
        count++;
    }

    // Step 5: If position is invalid
    if (PTR == NULL)
    {
        cout << "Invalid position" << endl;

        // return node back to AVAIL
        newNode->next = AVAIL;
        AVAIL = newNode;
        return;
    }

    // Step 6: Insert node (works for middle AND last position)
    newNode->next = PTR->next;
    newNode->prev = PTR;

    if (PTR->next != NULL) // if not inserting at end
        PTR->next->prev = newNode;

    PTR->next = newNode;
}

// Function to initialize AVAIL with free nodes
Node *initializeAvail(int n)
{
    Node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        Node *temp = new Node;
        temp->next = head;
        temp->prev = NULL; // important
        head = temp;
    }
    return head;
}

// Forward traversal function
void displayForward(Node *ptr) // ptr = START
{
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

int main()
{
    // Initialize AVAIL list
    Node *AVAIL = initializeAvail(5);

    // Get nodes from AVAIL
    Node *head = getNode(AVAIL);
    Node *second = getNode(AVAIL);
    Node *third = getNode(AVAIL);

    //  Assign data
    head->data = 10;
    second->data = 20;
    third->data = 30;

    // Link nodes
    head->prev = NULL;
    head->next = second;

    second->prev = head;
    second->next = third;

    third->prev = second;
    third->next = NULL;

    // Display original list
    cout << "Original list: ";
    displayForward(head);

    // Insert at last position using insertAtPosition
    insertAtPosition(head, AVAIL, 40, 4);

    // Display updated list
    cout << "\nAfter insertion: ";
    displayForward(head);

    return 0;
}
