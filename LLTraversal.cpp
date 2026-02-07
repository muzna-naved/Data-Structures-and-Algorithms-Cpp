// Linked List Traversal

#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *next;
};

// Traversal function
void display(Node *ptr) // PTR = START
{
    while (ptr != NULL) // Step 2: PTR != NULL
    {
        printf("%d", ptr->data); // Step 3: Process PTR->DATA
        cout << endl;
        ptr = ptr->next; // Step 4: PTR = PTR->NEXT
    }
}

// Main function
int main()
{
    // Create nodes
    Node *head = new Node(); // START
    Node *second = new Node();
    Node *third = new Node();

    // Assign data and links
    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    // Call traversal
    display(head); // display(START)

    return 0;
}
