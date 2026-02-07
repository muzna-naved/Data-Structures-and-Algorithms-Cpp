#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node *prev;
    Node *next;
};

// Forward traversal
void displayForward(Node *ptr) {
    while (ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

// Initialize AVAIL list
Node* initializeAvail(int n) {
    Node *AVAIL = NULL;
    for (int i = 0; i < n; i++) {
        Node *temp = new Node();
        temp->next = AVAIL;
        AVAIL = temp;
    }
    return AVAIL;
}

// Return node back to AVAIL
void freeNode(Node *&AVAIL, Node *node) {
    node->next = AVAIL;
    node->prev = NULL;
    AVAIL = node;
}

// Insert at end using AVAIL
void insertAtEnd(Node *&START, Node *&AVAIL, int val) {
    if (AVAIL == NULL) {
        cout << "OVERFLOW" << endl;
        return;
    }

    Node *newNode = AVAIL;
    AVAIL = AVAIL->next;
    newNode->data = val;
    newNode->next = NULL;

    if (START == NULL) {
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
void deleteAtPosition(Node *&START, Node *&AVAIL, int pos) {
    if (START == NULL) {
        cout << "UNDERFLOW" << endl;
        return;
    }

    if (pos <= 0) {
        cout << "INVALID POSITION" << endl;
        return;
    }

    Node *PTR = START;

    // Deleting first node
    if (pos == 1) {
        START = START->next;
        if (START != NULL)
            START->prev = NULL;
        freeNode(AVAIL, PTR);
        return;
    }

    // Traverse to the position
    int count = 1;
    while (PTR != NULL && count < pos) {
        PTR = PTR->next;
        count++;
    }

    if (PTR == NULL) {
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

int main() {
    Node *START = NULL;
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    Node *AVAIL = initializeAvail(n);

    cout << "Enter values for linked list:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertAtEnd(START, AVAIL, val);
    }

    cout << "Original List: ";
    displayForward(START);

    int pos;
    cout << "Enter position to delete: ";
    cin >> pos;

    deleteAtPosition(START, AVAIL, pos);

    cout << "After deletion: ";
    displayForward(START);

    return 0;
}
