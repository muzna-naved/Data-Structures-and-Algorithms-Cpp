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

// Function to count no of nodes
int countNodes(Node *head)
{
    int count = 0;
    Node *ptr = head;

    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }

    return count;
}

// Function to search a value
void searchValue(Node *head, int search)
{
    int pos = 1;
    Node *ptr = head;

    while (ptr != NULL)
    {
        if (ptr->data == search)
        {
            cout << "Target found at position : " << pos << endl;
            return;
        }
        ptr = ptr->next;
        pos++;
    }
    cout << "Target not found." << endl;
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
    // Count no of nodes
    cout << "\nNo of nodes: " << countNodes(head) << endl;
    // Search
    int search;
    cout << "Enter the value you want to search in Linkedlist: ";
    cin >> search;

    searchValue(head, search);

    return 0;
}
