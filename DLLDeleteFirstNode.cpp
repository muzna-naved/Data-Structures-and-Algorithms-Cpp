// Delete first node

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

// Insert at beginning using AVAIL
void insertAtBeginning(Node *&START, Node *&AVAIL, int val)
{
    // Step 1: If no free node is available, insertion is not possible
    if (AVAIL == NULL)
    {
        cout << "OVERFLOW" << endl;
        return;
    }

    // Step 2: Take the first free node from AVAIL
    Node *newNode = AVAIL;

    // Step 3: Move AVAIL to the next free node
    AVAIL = AVAIL->next;

    // Step 4: Put the given value into the new node
    newNode->data = val;

    // Step 5: Since this node will be the first, its prev will be NULL
    newNode->prev = NULL;

    // Step 6: Link new node to the current START node
    newNode->next = START;

    // Step 7: If list already exists, connect old START back to new node
    if (START != NULL)
    {
        START->prev = newNode;
    }

    // Step 8: Make new node the START of the list
    START = newNode;

}

// Delete first node
void deleteFirst(Node *&START, Node *&AVAIL)
{
    // Step 1: IF START = NULL
    if (START == NULL)
    {
        cout << "UNDERFLOW" << endl;
        return;
    }

    // Step 2: SET PTR = START
    Node *PTR = START;

    // Step 3: SET START = START->NEXT
    START = START->next;

    // Step 4: IF START != NULL, SET START->PREV = NULL
    if (START != NULL)
    {
        START->prev = NULL;
    }

    // Step 5: FREE PTR
    freeNode(AVAIL, PTR);

    // Step 6: EXIT
}

int main()
{
    Node *START = NULL;

    // Create AVAIL list with 5 free nodes
    Node *AVAIL = initializeAvail(5);

    insertAtBeginning(START, AVAIL, 10);
    insertAtBeginning(START, AVAIL, 20);
    insertAtBeginning(START, AVAIL, 30);

    cout << "After deleting first node: ";
    displayForward(START);

    return 0;
}
