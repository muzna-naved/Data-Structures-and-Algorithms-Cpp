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

// Insert VAL after node containing NUM
void insertAfter(Node *&START, int VAL, int NUM)
{
    // Step 1: Find NUM
    Node *PTR = START;
    while (PTR != NULL && PTR->data != NUM)
    {
        PTR = PTR->next;
    }

    // Step 2: If not found
    if (PTR == NULL)
    {
        cout << "Value " << NUM << " not found." << endl;
        return;
    }

    // Step 3: Create new node
    Node *NEW = new Node;
    NEW->data = VAL;

    // Step 4: Insert after NUM
    NEW->next = PTR->next;
    PTR->next = NEW;
}

// Display linked list
void display(Node *START)
{
    Node *PTR = START;
    while (PTR != NULL)
    {
        cout << PTR->data << " ";
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

    // User input list
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value: ";
        cin >> value;
        insertEnd(START, value);
    }

    cout << "\nOriginal List: ";
    display(START);

    int VAL, NUM;
    cout << "\nEnter value to insert: ";
    cin >> VAL;

    cout << "Insert after which value: ";
    cin >> NUM;

    insertAfter(START, VAL, NUM);

    cout << "\nUpdated List: ";
    display(START);

    return 0;
}
