#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *next;
};

// Insert node at end
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

// Delete first node
void deleteFirst(Node *&START)
{
    // Step 1: Check UNDERFLOW
    if (START == NULL)
    {
        cout << "UNDERFLOW (List is empty)" << endl;
        return;
    }

    // Step 2: Store first node
    Node *PTR = START;

    // Step 3: Move START to next node
    START = START->next;

    // Step 4: Delete old first node
    delete PTR;
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

    // User input linked list
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value: ";
        cin >> value;
        insertEnd(START, value);
    }

    cout << "\nOriginal List: ";
    display(START);

    // Delete first node
    deleteFirst(START);
    cout << "After deleting first node: ";
    display(START);

    return 0;
}
