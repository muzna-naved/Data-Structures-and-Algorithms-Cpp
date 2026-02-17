#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *next;
};

// Insert node at end (user input)
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

// Delete node with value NUM
void deleteNode(Node *&START, int NUM)
{
    // Step 1: UNDERFLOW check
    if (START == NULL)
    {
        cout << "UNDERFLOW (List is empty)" << endl;
        return;
    }

    // Case 1: First node contains NUM
    if (START->data == NUM)
    {
        Node *PTR = START;
        START = START->next;
        delete PTR;
        return;
    }

    // Case 2: Search NUM in list
    Node *PTR = START;
    Node *PREPTR = NULL;

    while (PTR != NULL && PTR->data != NUM)
    {
        PREPTR = PTR;
        PTR = PTR->next;
    }

    if (PTR == NULL)
    {
        cout << "VALUE NOT FOUND" << endl;
        return;
    }

    // Remove node
    PREPTR->next = PTR->next;
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
    int n, value, del;

    cout << "Enter number of nodes: ";
    cin >> n;

    // User input for list
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value: ";
        cin >> value;
        insertEnd(START, value);
    }

    cout << "\nOriginal List: ";
    display(START);

    cout << "\nEnter value to delete: ";
    cin >> del;
    deleteNode(START, del);

    cout << "List after deletion: ";
    display(START);

    return 0;
}
