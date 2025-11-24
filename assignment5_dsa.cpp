//assignment 5: DSA (Single Linked List)

//Q1
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Function to create a new node
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// (a) Insert at beginning
void insertAtBeginning(int value) {
    struct Node *newNode = createNode(value);
    newNode->next = head;
    head = newNode;
    printf("Inserted %d at the beginning.\n", value);
}

// (b) Insert at end
void insertAtEnd(int value) {
    struct Node *newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("Inserted %d at the end.\n", value);
}

// (c) Insert before or after a specific node
void insertBeforeAfter(int key, int value, int choice) {
    struct Node *newNode = createNode(value);
    struct Node *temp = head, *prev = NULL;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with value %d not found.\n", key);
        return;
    }

    if (choice == 1) { // insert before
        if (temp == head) {
            newNode->next = head;
            head = newNode;
        } else {
            prev->next = newNode;
            newNode->next = temp;
        }
        printf("Inserted %d before %d.\n", value, key);
    } else { // insert after
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Inserted %d after %d.\n", value, key);
    }
}

// (d) Delete from beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    printf("Deleted node %d from beginning.\n", temp->data);
    free(temp);
}

// (e) Delete from end
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head, *prev = NULL;
    if (head->next == NULL) {
        printf("Deleted node %d from end.\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    printf("Deleted node %d from end.\n", temp->data);
    prev->next = NULL;
    free(temp);
}

// (f) Delete specific node
void deleteSpecificNode(int key) {
    struct Node *temp = head, *prev = NULL;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->data == key) {
        head = head->next;
        printf("Deleted node %d.\n", key);
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with value %d not found.\n", key);
        return;
    }

    prev->next = temp->next;
    printf("Deleted node %d.\n", key);
    free(temp);
}

// (g) Search for a node
void searchNode(int key) {
    struct Node *temp = head;
    int position = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Node %d found at position %d.\n", key, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Node %d not found in the list.\n", key);
}

// (h) Display all nodes
void displayList() {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value, key, positionChoice;

    while (1) {
        printf("\n=== Singly Linked List Menu ===\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert Before/After Specific Node\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete Specific Node\n");
        printf("7. Search Node\n");
        printf("8. Display List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter existing node value: ");
                scanf("%d", &key);
                printf("Enter new node value: ");
                scanf("%d", &value);
                printf("1. Insert before\n2. Insert after\nEnter choice: ");
                scanf("%d", &positionChoice);
                insertBeforeAfter(key, value, positionChoice);
                break;
            case 4:
                deleteFromBeginning();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                printf("Enter node value to delete: ");
                scanf("%d", &key);
                deleteSpecificNode(key);
                break;
            case 7:
                printf("Enter node value to search: ");
                scanf("%d", &key);
                searchNode(key);
                break;
            case 8:
                displayList();
                break;
            case 9:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
//Q2

#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node *head = NULL; {
    int data;
    struct Nod e *next;
};
    
// Function to count and delete all occurrences of a given key
int countAndDeleteKey(int key) {
    struct Node *temp = head, *prev = NULL;
    int count = 0;

    // Handle deletions from the beginning
    while (head != NULL && head->data == key) {
        struct Node *del = head;
        head = head->next;
        free(del);
        count++;
    }

    // Traverse and delete remaining occurrences
    temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            struct Node *del = temp;
            prev->next = temp->next;
            temp = temp->next;
            free(del);
            count++;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }

    return count;
}

int main() {
    int key;

    // Create the example list: 1 -> 2 -> 1 -> 2 -> 1 -> 3 -> 1
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(1);
    insertAtEnd(3);
    insertAtEnd(1);

    printf("Original Linked List: ");
    displayList();

    printf("Enter key to delete: ");
    scanf("%d", &key);

    int count = countAndDeleteKey(key);

    printf("\nCount: %d\n", count);
    printf("Updated Linked List: ");
    displayList();

    return 0;
}


//Q3


#include <stdio.h>
#include <stdlib.h>

// Define a node
struct Node {
    int data;
    struct Node *next;
};

// Head pointer
struct Node *head = NULL;

// Function to create a new node
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at the end
void insertAtEnd(int value) {
    struct Node *newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Function to display the linked list
void displayList() {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
}

// Function to find the middle element
void findMiddle() {
    struct Node *slow = head, *fast = head;

    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    // Move fast by 2 steps and slow by 1 step
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    printf("Middle element: %d\n", slow->data);
}

int main() {
    int n, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insertAtEnd(val);
    }

    printf("\nLinked List: ");
    displayList();

    findMiddle();

    return 0;
}

//Q4

#include <stdio.h>
#include <stdlib.h>

// Define a node
struct Node {
    int data;
    struct Node *next;
};



int main() {    
    int n, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insertAtEnd(val);
    }

    printf("\nOriginal Linked List:\n");
    displayList();

    reverseList();

    printf("\nReversed Linked List:\n");
    displayList();

    return 0;
}             
