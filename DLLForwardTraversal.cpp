// DLL Forward traversal
#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *prev;
    Node *next;
};

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
    // Create nodes
    Node *head = new Node(); // START
    Node *second = new Node();
    Node *third = new Node();

    // Assign data and links

    head->data = 10;
    head->prev = NULL;
    head->next = second;

    second->data = 20;
    second->prev = head;
    second->next = third;

    third->data = 30;
    third->prev = second;
    third->next = NULL;

    // Forward traversal
    displayForward(head);

    return 0;
}
