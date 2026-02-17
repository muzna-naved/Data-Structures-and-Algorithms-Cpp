#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *next;
};

// Insert node at end (for user input)
void insertEnd(Node *&START, int val)
{
    Node *NEW = new Node;
    NEW->data = val;
    NEW->next = NULL;

    if (START == NULL)
    {
        START = NEW;
        return;
    }

    Node *PTR = START;
    while (PTR->next != NULL)
    {
        PTR = PTR->next;
    }
    PTR->next = NEW;
}

// Delete last node
void deleteLast(Node *&START)
{
    // Step 1: Check UNDERFLOW
    if (START == NULL)
    {
        cout << "UNDERFLOW (List is empty)" << endl;
        return;
    }

    // Case 1: Only one node
    if (START->next == NULL)
    {
        delete START;
        START = NULL;
        return;
    }

    // Case 2: More than one node
    Node *PTR = START;
    Node *PREPTR = NULL;

    while (PTR->next != NULL)
    {
        PREPTR = PTR;
        PTR = PTR->next;
    }

    PREPTR->next = NULL; // disconnect last node
    delete PTR;          // delete last node
}

// Display linked list
void display(Node *START)
{
    Node *PTR = START;
    while (PTR != NULL)
    {
        cout << PTR->data << " -> ";
        PTR = PTR->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node *START = NULL;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    // User input for linked list
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value: ";
        cin >> value;
        insertEnd(START, value);
    }

    cout << "\nOriginal List: ";
    display(START);

    // Delete last node
    deleteLast(START);
    cout << "After deleting last node: ";
    display(START);

    // Delete again
    deleteLast(START);
    cout << "After deleting again: ";
    display(START);

    return 0;
}
