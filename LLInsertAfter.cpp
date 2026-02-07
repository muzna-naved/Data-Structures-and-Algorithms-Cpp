// Insert after a node

#include <iostream>
using namespace std;

// Define node structure
struct Node
{
    int data;
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
    return newNode;
}

// Function to insert after a node with value NUM
void insertAfter(Node *&START, Node *&AVAIL, int VAL, int NUM)
{
    // Step1-3: Take  node from AVAIL
    Node *newNode = getNode(AVAIL);
    if (newNode == NULL)
    {
        return; // no free nodes
    }

    // Step 4: Assign data
    newNode->data = VAL;

    // Step 5-6: Traverse to find NUM
    Node *PTR = START;
    while (PTR != NULL && PTR->data != NUM)
    {
        PTR = PTR->next;
    }

    // Step 7: if NUM not found
    if (PTR == NULL)
    {
        cout << "Node with value " << NUM << " Not found. " << endl;

        // Return node back to AVAIL
        newNode->next = AVAIL;
        AVAIL = newNode;
        return;
    }

    // Step 8-9: Insert after NUM
    newNode->next = PTR->next;
    PTR->next = newNode;
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

// Function to initialize AVAIL with free nodes
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

// Main function
int main()
{
    Node *START = NULL;
    Node *AVAIL = initializeAvail(10); // pool of 10 free nodes

    // Manually build a linked list : 10 -> 20 -> 30
    Node *n1 = getNode(AVAIL);
    n1->data = 10;
    START = n1;

    Node *n2 = getNode(AVAIL);
    n2->data = 20;
    n1->next = n2;

    Node *n3 = getNode(AVAIL);
    n3->data = 30;
    n2->next = n3;
    n3->next = NULL;

    cout << "Original List: ";
    display(START);

    // insert 25after 20
    insertAfter(START, AVAIL, 25, 20);
    cout << "After inserting 25 after 20: ";
    display(START);

    // Try inserting after non-existing node
    insertAfter(START, AVAIL, 40, 50);
    cout << "Final List: ";
    display(START);

    return 0;
}
