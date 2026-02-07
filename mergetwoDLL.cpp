// merge two doubly linked list
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
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Merge two doubly linked lists 
Node* mergeLists(Node *list1, Node *list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    Node *temp = list1;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = list2;
    list2->prev = temp;

    return list1;
}

int main() {
    int n1, n2, val;
    cout << "Enter number of nodes for first list: ";
    cin >> n1;
    cout << "Enter number of nodes for second list: ";
    cin >> n2;

    int totalNodes = n1 + n2;
    Node *AVAIL = initializeAvail(totalNodes);

    Node *list1 = NULL;
    Node *list2 = NULL;

    cout << "Enter values for first list:\n";
    for (int i = 0; i < n1; i++) {
        cin >> val;
        insertAtEnd(list1, AVAIL, val);
    }

    cout << "Enter values for second list:\n";
    for (int i = 0; i < n2; i++) {
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

    return 0;
}
