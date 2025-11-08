//ASSIGNMENT 4: QUEUES 

//Q1

#include <stdio.h>
#include <stdlib.h>
#define MAX 5   // Maximum size of Queue

int queue[MAX];
int front = -1, rear = -1;

// Function to check if queue is empty
int isEmpty() {
    return (front == -1);
}

// Function to check if queue is full
int isFull() {
    return (rear == MAX - 1);
}

// Function to add element to queue
void enqueue(int data) {
    if (isFull()) {
        printf("\nQueue is Full! Cannot insert %d.\n", data);
        return;
    }
    if (front == -1) front = 0; // First element
    queue[++rear] = data;
    printf("%d enqueued to queue.\n", data);
}

// Function to remove element from queue
void dequeue() {
    if (isEmpty()) {
        printf("\nQueue is Empty! Nothing to dequeue.\n");
        return;
    }
    printf("%d dequeued from queue.\n", queue[front]);
    front++;
    if (front > rear) front = rear = -1; // Reset queue if empty
}

// Function to view the front element
void peek() {
    if (isEmpty()) {
        printf("\nQueue is Empty!\n");
        return;
    }
    printf("Front element is: %d\n", queue[front]);
}

// Function to display queue elements
void display() {
    if (isEmpty()) {
        printf("\nQueue is Empty!\n");
        return;
    }
    printf("\nQueue elements: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

// Main menu-driven function
int main() {
    int choice, value;

    while (1) {
        printf("\n=== Queue Operations ===\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Check if Empty\n6. Check if Full\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            if (isEmpty()) printf("Queue is Empty.\n");
            else printf("Queue is NOT Empty.\n");
            break;
        case 6:
            if (isFull()) printf("Queue is Full.\n");
            else printf("Queue is NOT Full.\n");
            break;
        case 7:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}


//Q2

#include <stdio.h>
#include <stdlib.h>
#define MAX 5   // maximum size of the circular queue

int queue[MAX];
int front = -1, rear = -1;

// Function to check if the queue is empty
int isEmpty() {
    return (front == -1);
}

// Function to check if the queue is full
int isFull() {
    return ((rear + 1) % MAX == front);
}

// Function to insert an element
void enqueue(int value) {
    if (isFull()) {
        printf("\nQueue is Full! Cannot insert %d.\n", value);
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    queue[rear] = value;
    printf("%d enqueued to queue.\n", value);
}

// Function to delete an element
void dequeue() {
    if (isEmpty()) {
        printf("\nQueue is Empty! Nothing to dequeue.\n");
        return;
    }
    printf("%d dequeued from queue.\n", queue[front]);
    if (front == rear) {
        // Only one element was there
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// Function to view the front element
void peek() {
    if (isEmpty()) {
        printf("\nQueue is Empty!\n");
        return;
    }
    printf("Front element is: %d\n", queue[front]);
}

// Function to display the queue
void display() {
    if (isEmpty()) {
        printf("\nQueue is Empty!\n");
        return;
    }
    printf("\nQueue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Main function with menu
int main_q2() {
    int choice, value;

    while (1) {
        printf("\n=== Circular Queue Operations ===\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Check if Empty\n6. Check if Full\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {   
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            if (isEmpty()) printf("Queue is Empty.\n");
            else printf("Queue is NOT Empty.\n");
            break;
        case 6:
            if (isFull()) printf("Queue is Full.\n");
            else printf("Queue is NOT Full.\n");
            break;
        case 7:
            printf("Exiting...\n");
            exit(0);
            break;
        default:
            printf("Invalid choice! Please try again.\n");
            break;
    }
    return 0;
}
//Q3
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// Enqueue function
void enqueue(int x) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = x;
}

// Dequeue function
int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        exit(1);
    }
    return queue[front++];
}

// Display function
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
        return;
    }
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

// Function to interleave first half with second half
void interleaveQueue(int n) {
    if (n % 2 != 0) {
        printf("Queue must contain even number of elements.\n");
        return;
    }

    int half = n / 2;
    int temp[MAX];
    int tempFront = 0, tempRear = -1;

    // Step 1: Move first half elements to temp queue
    for (int i = 0; i < half; i++)
        temp[++tempRear] = dequeue();

    // Step 2: Interleave the two halves
    while (tempFront <= tempRear) {
        enqueue(temp[tempFront++]);   // Add from first half
        enqueue(dequeue());           // Add from second half
    }
}

int main() {
    int n, x;
    printf("Enter number of elements (even number): ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    printf("\nOriginal Queue: ");
    display();

    interleaveQueue(n);

    printf("\nInterleaved Queue: ");
    display();

    return 0;
}
//Q4
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int q1[MAX], q2[MAX];
int front1 = -1, rear1 = -1;
int front2 = -1, rear2 = -1;

// Queue Operations
void enqueue1(int x) {
    if (rear1 == MAX - 1) return;
    if (front1 == -1) front1 = 0;
    q1[++rear1] = x;
}

int dequeue1() {
    if (front1 == -1 || front1 > rear1) return -1;
    return q1[front1++];
}

void enqueue2(int x) {
    if (rear2 == MAX - 1) return;
    if (front2 == -1) front2 = 0;
    q2[++rear2] = x;
}

int dequeue2() {
    if (front2 == -1 || front2 > rear2) return -1;
    return q2[front2++];
}

// Check if stack is empty
int isEmpty() {
    return (front1 == -1 || front1 > rear1);
}

// Push operation using two queues
void push(int x) {
    // Step 1: Enqueue new element into q2
    enqueue2(x);

    // Step 2: Move all elements from q1 to q2
    while (!isEmpty()) {
        enqueue2(dequeue1());
    }

    // Step 3: Swap q1 and q2
    int temp[MAX], tFront, tRear;

    for (int i = 0; i < MAX; i++)
        temp[i] = q1[i];
    for (int i = 0; i < MAX; i++)
        q1[i] = q2[i];
    for (int i = 0; i < MAX; i++)
        q2[i] = temp[i];

    tFront = front1; front1 = front2; front2 = tFront;
    tRear = rear1; rear1 = rear2; rear2 = tRear;
}

// Pop operation
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return pop();
}

int main_q4() {
    int x;
    printf("Enter element to push: ");
    scanf("%d", &x);
    push(x);
    printf("Popped element: %d\n", pop());
    return 0;
}   

//Q5

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int q1[MAX], q2[MAX];
int front1 = -1, rear1 = -1;
int front2 = -1, rear2 = -1;

// Queue operations
void enqueue1(int x) {
    if (rear1 == MAX - 1) return;
    if (front1 == -1) front1 = 0;
    q1[++rear1] = x;
}

int dequeue1() {
    if (front1 == -1 || front1 > rear1) return -1;
    return q1[front1++];
}

void enqueue2(int x) {
    if (rear2 == MAX - 1) return;
    if (front2 == -1) front2 = 0;
    q2[++rear2] = x;
}

int dequeue2() {
    if (front2 == -1 || front2 > rear2) return -1;
    return q2[front2++];
}

// Check if stack is empty
int isEmpty1() {
    return (front1 == -1 || front1 > rear1);
}

// Push operation
void push(int x) {
    enqueue2(x); // Step 1: Put new element in q2

    // Step 2: Move all elements from q1 to q2
    while (!isEmpty1()) {
        enqueue2(dequeue1());
    }

    // Step 3: Swap q1 and q2
    int temp[MAX], tFront, tRear;
    for (int i = 0; i < MAX; i++)
        temp[i] = q1[i];
    for (int i = 0; i < MAX; i++)
        q1[i] = q2[i];
    for (int i = 0; i < MAX; i++)
        q2[i] = temp[i];

    tFront = front1; front1 = front2; front2 = tFront;
    tRear = rear1; rear1 = rear2; rear2 = tRear;
}

// Pop operation
int pop() {
    if (isEmpty1()) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return dequeue1();
}

// Display stack
void display() {
    if (isEmpty1()) {
        printf("Stack is Empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = front1; i <= rear1; i++)
        printf("%d ", q1[i]);
    printf("\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("\n=== Stack using Two Queues ===\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            value = pop();
            if (value != -1)
                printf("Popped: %d\n", value);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
}
