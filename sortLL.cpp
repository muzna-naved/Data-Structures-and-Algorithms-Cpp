// sort the linked list in ascending order.

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
{
    // Step 1: Create a new node
    Node *newNode = new (nothrow) Node; // nothrow prevents crash if memory fails

    if (newNode == NULL)
    {
        // Step 1A: check (Overflow)
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

// Function to sort LL
void sortList(Node *head)
{
    Node *ptr;
    Node *largest;

    for (largest = head; largest != NULL; largest = largest->next)
    {
        for (ptr = largest->next; ptr != NULL; ptr = ptr->next)
        {
            if (ptr->data < largest->data)
            {
                swap(ptr->data, largest->data);
            }
        }
    }
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
        insertAtBeginning(start, value);
    }

    cout << "Linked List after insertions: ";
    traverse(start);
    // Sorted LL
    cout << "Sorted List:";
    sortList(start);
    // Print LL in reversed order
    traverse(start);

    return 0;
}
