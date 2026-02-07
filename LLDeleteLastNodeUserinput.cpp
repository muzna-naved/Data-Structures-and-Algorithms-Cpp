#include <iostream>
using namespace std;

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

// Delete the last node and return it to AVAIL
void deleteLast(Node *&START, Node *&AVAIL)
{
    if (START == NULL)
    {
        cout << "UNDERFLOW" << endl;
        return;
    }

    if (START->next == NULL)
    {
        Node *PTR = START;
        START = NULL;
        freeNode(AVAIL, PTR);
        return;
    }

    Node *PTR = START;
    Node *PREPTR = NULL;

    while (PTR->next != NULL)
    {
        PREPTR = PTR;
        PTR = PTR->next;
    }

    PREPTR->next = NULL;
    freeNode(AVAIL, PTR);
}

// Display linked list
void display(Node *start)
{
    Node *temp = start;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Initialize AVAIL list
Node *initializeAvail(int n)
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
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    Node *AVAIL = initializeAvail(n + 5); // extra safety
    Node *START = NULL;
    Node *LAST = NULL;

    for (int i = 0; i < n; i++)
    {
        if (AVAIL == NULL)
        {
            cout << "OVERFLOW" << endl;
            break;
        }

        Node *NEW = AVAIL; // take node from AVAIL
        AVAIL = AVAIL->next;

        cout << "Enter data for node " << i + 1 << ": ";
        cin >> NEW->data;
        NEW->next = NULL;

        if (START == NULL)
        {
            START = NEW;
            LAST = NEW;
        }
        else
        {
            LAST->next = NEW;
            LAST = NEW;
        }
    }

    cout << "\nOriginal List: ";
    display(START);

    deleteLast(START, AVAIL);
    cout << "After deleting last node: ";
    display(START);

    deleteLast(START, AVAIL);
    cout << "After deleting again: ";
    display(START);

    return 0;
}
