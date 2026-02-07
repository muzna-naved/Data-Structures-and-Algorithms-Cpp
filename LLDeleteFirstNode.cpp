// Delete first node

#include <iostream>
using namespace std;

//Node structure
struct Node
{
    int data;
    Node *next;
};

// Return node back to AVAIL list
void freeNode(Node *&AVAIL, Node *node)
{
    node->next = AVAIL;
    AVAIL = node;
}

// Delete first node and return it to AVAIL
void deleteFirst(Node *&START, Node *&AVAIL)
{
    if (START == NULL)
    {
        cout << "UNDERFLOW" << endl;
        return;
    }

    Node *PTR = START;    // Step 2
    START = START->next;  // Step 3
    freeNode(AVAIL, PTR); // Step 4(instead of delete)
}

void display(Node *start)
{
    Node *temp = start;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node *initializeAVAIL(int n)
{
    Node *head = NULL;

    for (int i = 0; i < n; i++)
    {
        Node *temp = new Node;
        temp->next = head;
        head = temp;
    }
    return head;
}

int main()
{
    Node *AVAIL = initializeAVAIL(10); // free pool
    Node *START = NULL;

    // Take 3 nodes from AVAIL to build: 10 ->2- ->30
    Node *n1 = AVAIL;
    AVAIL = AVAIL->next;
    n1->data = 10;

    Node *n2 = AVAIL;
    AVAIL = AVAIL->next;
    n2->data = 20;

    Node *n3 = AVAIL;
    AVAIL = AVAIL->next;
    n3->data = 30;

    n1->next = n2;

    n2->next = n3;

    n3->next = NULL;

    START = n1;

    cout << "Original List: ";
    display(START);

    deleteFirst(START, AVAIL);
    cout << "After deleting first node: ";
    display(START);

    deleteFirst(START, AVAIL);
    cout << "After deleting first node again: ";
    display(START);

    deleteFirst(START, AVAIL);
    cout << "After deleting last node: ";
    display(START);

    deleteFirst(START, AVAIL); // empty case
}