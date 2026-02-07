// Insertion of new node at the beginning
#include <iostream>
using namespace std;

// Define node structure
struct Node
{
    int data;
    Node *next;
};

// Function to insert a node at the beginning
void insertAtBeginning(Node *&start, int val) // & is used for pass by reference (Allows modifying original pointer)
{   // Step 1: Create a new node
    Node *newNode = new (nothrow) Node;       // nothrow prevents crash if memory fails
    if (newNode == NULL)
    { // Step 1A: check (Overflow)
        cout << "OVERFLOW: No memory available!" << endl;
        return;
    }
    // Step 2: Assign value to new node
    newNode->data = val;
    // Step 3: Point new node to current start
    newNode->next = start; // New node points to old first node
    // Step 4: Update start
    start = newNode; // new node becomes the first node
}

// Function to traverse and display linked list
void traverse(Node *start)
{
    Node *ptr = start;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

// Main function
int main()
{
    Node *start = NULL; // Initially empty list
    // Insert nodes at the beginning
    insertAtBeginning(start, 30);
    insertAtBeginning(start, 20);
    insertAtBeginning(start, 10);

    cout << "Linked List after insertions:";
    traverse(start);

    return 0;
}