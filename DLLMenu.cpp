// Menu driven
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

// Return node back to AVAIL
void freeNode(Node *&AVAIL, Node *node)
{
    node->next = AVAIL;
    node->prev = NULL;
    AVAIL = node;
}

// Insert at end using AVAIL
void insertAtEnd(Node *&START, Node *&AVAIL, int val)
{
    if (AVAIL == NULL)
    {
        cout << "OVERFLOW" << endl;
        return;
    }

    Node *newNode = AVAIL;
    AVAIL = AVAIL->next;
    newNode->data = val;
    newNode->next = NULL;

    if (START == NULL)
    {
        newNode->prev = NULL;
        START = newNode;
        return;
    }

    Node *temp = START;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Delete node at a given position (1-based index)
void deleteAtPosition(Node *&START, Node *&AVAIL, int pos)
{
    if (START == NULL)
    {
        cout << "UNDERFLOW" << endl;
        return;
    }

    if (pos <= 0)
    {
        cout << "INVALID POSITION" << endl;
        return;
    }

    Node *PTR = START;

    // Deleting first node
    if (pos == 1)
    {
        START = START->next;
        if (START != NULL)
            START->prev = NULL;
        freeNode(AVAIL, PTR);
        return;
    }

    // Traverse to the position
    int count = 1;
    while (PTR != NULL && count < pos)
    {
        PTR = PTR->next;
        count++;
    }

    if (PTR == NULL)
    {
        cout << "POSITION NOT FOUND" << endl;
        return;
    }

    // Disconnect PTR
    if (PTR->prev != NULL)
        PTR->prev->next = PTR->next;

    if (PTR->next != NULL)
        PTR->next->prev = PTR->prev;

    freeNode(AVAIL, PTR);
}

void reverseList(Node *&head)
{
    Node *curr = head;
    Node *temp = NULL;

    while (curr != NULL)
    {
        // Swap next and prev
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        // Move to next node (was prev)
        curr = curr->prev;
    }

    // Update head (last node becomes head)
    if (temp != NULL)
    {
        head = temp->prev;
    }
}

// Merge two doubly linked lists
Node *mergeLists(Node *list1, Node *list2)
{
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    Node *temp = list1;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = list2;
    list2->prev = temp;

    return list1;
}

int main()
{
    Node *START = NULL;
    Node *AVAIL = NULL;
    int n, val, pos, ch;

    cout << "Enter number of nodes: ";
    cin >> n;

    AVAIL = initializeAvail(n);

    cout << "Enter values for linked list:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        insertAtEnd(START, AVAIL, val);
    }

    cout << "Original List: ";
    displayForward(START);

    cout << "\n-----Menu Options----\n";
    cout << "1.Delete a node at a position.\n";
    cout << "2.Reverse the doubly Linked List.\n";
    cout << "3.Merge two doubly Linked Lists.\n";

    cout << "Enter your choice: ";
    cin >> ch;

    switch (ch)
    {
    case 1:
        cout << "Enter position to delete: ";
        cin >> pos;
        deleteAtPosition(START, AVAIL, pos);
        cout << "After deletion: ";
        displayForward(START);
        break;

    case 2:
        reverseList(START);
        cout << "Reversed Linked List: ";
        displayForward(START);
        break;

    case 3:
    {
        int n1, n2;
        cout << "Enter number of nodes for first list: ";
        cin >> n1;
        cout << "Enter number of nodes for second list: ";
        cin >> n2;

        Node *list1 = NULL;
        Node *list2 = NULL;

        // Reuse AVAIL for total nodes
        AVAIL = initializeAvail(n1 + n2);

        cout << "Enter values for first list:\n";
        for (int i = 0; i < n1; i++)
        {
            cin >> val;
            insertAtEnd(list1, AVAIL, val);
        }

        cout << "Enter values for second list:\n";
        for (int i = 0; i < n2; i++)
        {
            cin >> val;
            insertAtEnd(list2, AVAIL, val);
        }

        cout << "First List: ";
        displayForward(list1);

        cout << "Second List: ";
        displayForward(list2);

        Node *merged = mergeLists(list1, list2);

        cout << "Merged List: ";
        displayForward(merged);
        break;
    }

    default:
        cout << "Invalid choice.";
        break;
    }

    return 0;
}
