#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;   // data part
    Node *next; // stores address of next node
};

// Function to print LL
void printList(Node *head)
{
    Node *temp = head;   // First node
    while (temp != NULL) // Loop runs until reaches null
    {
        cout << temp->data << " -> "; // access data value

        temp = temp->next; // move to next node using address stored in next
    }
    cout << "NULL" << endl;
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
    Node *ptr = head;

    while (ptr != NULL)
    {
        if (ptr->data == search)
        {
            cout << "Target found." << endl;
            return;
        }
        ptr = ptr->next;
    }
    cout << "Target not found." << endl;
}

// Function to reverse LL
void reverseList(Node *&head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next; // save next node
        curr->next = prev; // reverse link
        prev = curr;       // move prev
        curr = next;       // move curr
    }

    head = prev; // update head
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
    // Create nodes
    Node *head = new Node();   // First node
    Node *second = new Node(); // Second node
    Node *third = new Node();  // third node

    // Assign data and links
    head->data = 10;      // first node value is 10
    head->next = second;  // first node link to second
    second->data = 20;    // second node value is 20
    second->next = third; // second node link to third
    third->data = 30;     // third node value is 30
    third->next = NULL;   // third node links to null that means there is no more nodes

    // Print the linked list
    printList(head); // starts printing from first node and so on
    // Count no of nodes
    cout << "No of nodes: " << countNodes(head) << endl;
    searchValue(head, 10);
    // Reverse the LL
    cout << "Reversed Linked List: " << endl;
    reverseList(head);
    // Print LL in reversed order
    printList(head);
    // Sorted LL
    cout << "Sorted List:" << endl;
    sortList(head);
    // Print LL in sorted order
    printList(head);

    return 0;
}