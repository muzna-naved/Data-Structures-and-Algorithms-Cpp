// Count no of nodes
#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *prev;
    Node *next;
};

// Forward traversal
void displayForward(Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

// Initialize AVAIL list
Node *initializeAvail(int n)
{
    Node *AVAIL = NULL;
    for (int i = 0; i < n; i++)
    {
        Node *temp = new Node();
        temp->next = AVAIL;
        AVAIL = temp;
    }
    return AVAIL;
}

// Insert at beginning using AVAIL
void insertAtBeginning(Node *&START, Node *&AVAIL, int val)
{
    // Step 1: If no free node is available, insertion is not possible
    if (AVAIL == NULL)
    {
        cout << "OVERFLOW" << endl;
        return;
    }

    // Step 2: Take the first free node from AVAIL
    Node *newNode = AVAIL;

    // Step 3: Move AVAIL to the next free node
    AVAIL = AVAIL->next;

    // Step 4: Put the given value into the new node
    newNode->data = val;

    // Step 5: Since this node will be the first, its prev will be NULL
    newNode->prev = NULL;

    // Step 6: Link new node to the current START node
    newNode->next = START;

    // Step 7: If list already exists, connect old START back to new node
    if (START != NULL)
    {
        START->prev = newNode;
    }

    // Step 8: Make new node the START of the list
    START = newNode;
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

int main()
{
    Node *START = NULL;

    int n, val;

    // Ask user for number of nodes
    cout << "Enter number of nodes: ";
    cin >> n;

    // AVAIL list
    Node *AVAIL = initializeAvail(n);

    // Take data from user and insert
    for (int i = 1; i <= n; i++)
    {
        cout << "Enter value for node " << i << ": ";
        cin >> val;
        insertAtBeginning(START, AVAIL, val);
    }

    // Display list
    cout << "Doubly Linked List: ";
    displayForward(START);
    // Count no of nodes
    cout << "No of nodes: " << countNodes(START) << endl;

    return 0;
}
