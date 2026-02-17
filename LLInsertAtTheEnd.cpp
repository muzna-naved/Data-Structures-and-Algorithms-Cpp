// Insert new nodes at the end
#include <iostream>
using namespace std;

// Define a node of the linked list
struct Node
{
    int data;
    Node *next;
};

// Function to traverse and print the linked list
void traverse(Node *start)
{
    Node *ptr = start; // Step 1: Initialize PTR = START
    // Step 2: Repeat while PTR != NULL
    while (ptr != NULL)
    {
        cout << ptr->data << " "; // Step 3: Process PTR->DATA
        ptr = ptr->next;          // Step 4: PTR->NEXT
    }
    cout << endl;
}

// Utility function to add a new node at the end
void insertEnd(Node *&start, int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (start == NULL)
    {
        start = newNode;
        return;
    }

    Node *temp = start;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Main function

int main()
{
    Node *start = NULL;

    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter value: ";
        cin >> value;
        insertEnd(start, value);
    }

    cout << "Linked List after insertions: ";
    traverse(start);

    return 0;
}
