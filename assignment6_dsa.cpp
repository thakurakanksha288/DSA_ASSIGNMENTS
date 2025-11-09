//ASSIGNMENT 6: DSA (doubly LINKED LIST)

//Q1

#include <iostream>
using namespace std;

// Node structure for Doubly Circular Linked List
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Global pointer
Node* head = NULL;

// Function to insert at the beginning
void insertAtBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    if (head == NULL) {
        newNode->next = newNode->prev = newNode;
        head = newNode;
        return;
    }
    Node* last = head->prev;
    newNode->next = head;
    newNode->prev = last;
    last->next = newNode;
    head->prev = newNode;
    head = newNode;
}

// Function to insert at the end
void insertAtEnd(int value) {
    if (head == NULL) {
        insertAtBeginning(value);
        return;
    }
    Node* newNode = new Node();
    newNode->data = value;
    Node* last = head->prev;
    newNode->next = head;
    newNode->prev = last;
    last->next = newNode;
    head->prev = newNode;
}

// Function to insert after a specific node
void insertAfter(int key, int value) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    do {
        if (temp->data == key) {
            Node* newNode = new Node();
            newNode->data = value;
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);
    cout << "Node " << key << " not found.\n";
}

// Function to delete a node by value
void deleteNode(int key) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    Node* del = NULL;
    do {
        if (temp->data == key) {
            del = temp;
            break;
        }
        temp = temp->next;
    } while (temp != head);

    if (del == NULL) {
        cout << "Node " << key << " not found.\n";
        return;
    }

    if (del->next == del && del->prev == del) {
        head = NULL;
    } else {
        del->prev->next = del->next;
        del->next->prev = del->prev;
        if (del == head)
            head = del->next;
    }

    delete del;
    cout << "Node " << key << " deleted.\n";
}

// Function to search for a node
void searchNode(int key) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    int pos = 1;
    do {
        if (temp->data == key) {
            cout << "Node " << key << " found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    cout << "Node " << key << " not found.\n";
}

// Function to display the list
void displayList() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    cout << "List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// Main Menu
int main() {
    int choice, value, key;
    do {
        cout << "\n--- Doubly Circular Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Node\n";
        cout << "4. Delete a Node\n";
        cout << "5. Search a Node\n";
        cout << "6. Display List\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            insertAtBeginning(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            insertAtEnd(value);
            break;
        case 3:
            cout << "Enter node value after which to insert: ";
            cin >> key;
            cout << "Enter value to insert: ";
            cin >> value;
            insertAfter(key, value);
            break;
        case 4:
            cout << "Enter node value to delete: ";
            cin >> key;
            deleteNode(key);
            break;
        case 5:
            cout << "Enter node value to search: ";
            cin >> key;
            searchNode(key);
            break;
        case 6:
            displayList();
            break;
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 7);

    return 0;
}


//Q2

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Global pointer
Node* head = NULL;

// Function to insert at the end (for easy list creation)
void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }
    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
}

// Function to display the circular linked list
void displayCircularList() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    cout << "Output: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << head->data << endl; // Repeat head node value at the end
}

// Main function
int main() {
    // Input: 20 → 100 → 40 → 80 → 60
    insertAtEnd(20);
    insertAtEnd(100);
    insertAtEnd(40);
    insertAtEnd(80);
    insertAtEnd(60);

    cout << "Circular Linked List:\n";
    displayCircularList();

    return 0;
}


//Q3

#include <iostream>
using namespace std;

// ---------- DOUBLY LINKED LIST ----------
struct DNode {
    int data;
    DNode* next;
    DNode* prev;
};

DNode* dHead = NULL;

// Function to insert node at end (Doubly Linked List)
void insertDoubly(int value) {
    DNode* newNode = new DNode();
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (dHead == NULL) {
        dHead = newNode;
        return;
    }

    DNode* temp = dHead;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Function to find size of Doubly Linked List
int sizeOfDoubly() {
    int count = 0;
    DNode* temp = dHead;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}


// ---------- CIRCULAR LINKED LIST ----------
struct CNode {
    int data;
    CNode* next;
};

CNode* cHead = NULL;

// Function to insert node at end (Circular Linked List)
void insertCircular(int value) {
    CNode* newNode = new CNode();
    newNode->data = value;

    if (cHead == NULL) {
        cHead = newNode;
        newNode->next = cHead;
        return;
    }

    CNode* temp = cHead;
    while (temp->next != cHead)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = cHead;
}

// Function to find size of Circular Linked List
int sizeOfCircular() {
    if (cHead == NULL)
        return 0;

    int count = 0;
    CNode* temp = cHead;
    do {
        count++;
        temp = temp->next;
    } while (temp != cHead);

    return count;
}


// ---------- MAIN FUNCTION ----------
int main() {
    // Doubly Linked List example: 10 → 20 → 30
    insertDoubly(10);
    insertDoubly(20);
    insertDoubly(30);

    cout << "Doubly Linked List Size: " << sizeOfDoubly() << endl;

    // Circular Linked List example: 5 → 15 → 25 → 35
    insertCircular(5);
    insertCircular(15);
    insertCircular(25);
    insertCircular(35);

    cout << "Circular Linked List Size: " << sizeOfCircular() << endl;

    return 0;
}


//Q4

#include <iostream>
using namespace std;

// Structure for Doubly Linked List Node
struct Node {
    char data;
    Node* next;
    Node* prev;
};

Node* head = NULL;

// Function to insert a character at the end
void insertAtEnd(char value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Function to check if the doubly linked list is palindrome
bool isPalindrome() {
    if (head == NULL)
        return true; // Empty list is palindrome

    Node* left = head;
    Node* right = head;

    // Move right to the end of the list
    while (right->next != NULL)
        right = right->next;

    // Compare characters from both ends
    while (left != right && right->next != left) {
        if (left->data != right->data)
            return false;
        left = left->next;
        right = right->prev;
    }

    return true;
}

// Function to display the list
void displayList() {
    Node* temp = head;
    cout << "List: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Main Function
int main() {
    int n;
    char ch;

    cout << "Enter number of characters: ";
    cin >> n;

    cout << "Enter characters one by one:\n";
    for (int i = 0; i < n; i++) {
        cin >> ch;
        insertAtEnd(ch);
    }

    displayList();

    if (isPalindrome())
        cout << "The given Doubly Linked List is a Palindrome.\n";
    else
        cout << "The given Doubly Linked List is NOT a Palindrome.\n";

    return 0;
}


//Q5
#include <iostream>
using namespace std;

// Structure for a node
struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Function to insert node at the end
void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Function to make the list circular (for testing)
void makeCircular() {
    if (head == NULL)
        return;

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head; // Last node now points to head
}

// Function to check if the linked list is circular
bool isCircular() {
    if (head == NULL)
        return false;  // Empty list is not circular by default

    Node* temp = head->next;

    // Traverse and check if we come back to head
    while (temp != NULL && temp != head)
        temp = temp->next;

    return (temp == head);
}

// Display the list (for reference, shows up to 10 nodes only)
void displayList() {
    Node* temp = head;
    int count = 0;
    cout << "List: ";
    while (temp != NULL && count < 10) {  // Limit to prevent infinite loop
        cout << temp->data << " ";
        temp = temp->next;
        count++;
    }
    cout << endl;
}

// Main function
int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);

    cout << "Initially:\n";
    displayList();
    cout << (isCircular() ? "The list is Circular.\n" : "The list is NOT Circular.\n");

    // Make the list circular for testing
    makeCircular();
    cout << "\nAfter making it circular:\n";
    cout << (isCircular() ? "The list is Circular.\n" : "The list is NOT Circular.\n");

    return 0;
}
