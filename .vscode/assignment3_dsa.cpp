//ASSIGNMENT 3: STACKS
//Q1

#include <stdio.h>
#include <stdlib.h>

#define MAX 5   // Maximum size of the stack

int stack[MAX];
int top = -1;

// Function to check if stack is full
int isFull() {
    return top == MAX - 1;
}

// Function to check if stack is empty
int isEmpty() {
    return top == -1;
}

// Function to push an element into stack
void push() {
    int value;
    if (isFull()) {
        printf("\nStack Overflow! Cannot push element.\n");
    } else {
        printf("Enter element to push: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
        printf("%d pushed into stack.\n", value);
    }
}

// Function to pop an element from stack
void pop() {
    if (isEmpty()) {
        printf("\nStack Underflow! No element to pop.\n");
    } else {
        printf("Popped element: %d\n", stack[top]);
        top--;
    }
}

// Function to display the stack elements
void display() {
    if (isEmpty()) {
        printf("\nStack is empty.\n");
    } else {
        printf("\nStack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

// Function to return the top element (peek)
void peek() {
    if (isEmpty()) {
        printf("\nStack is empty.\n");
    } else {
        printf("\nTop element is: %d\n", stack[top]);
    }
}

// Main function
int main() {
    int choice;
    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Check if Empty\n");
        printf("4. Check if Full\n");
        printf("5. Display Stack\n");
        printf("6. Peek (Top Element)\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: 
                if (isEmpty()) printf("Stack is empty.\n");
                else printf("Stack is not empty.\n");
                break;
            case 4:
                if (isFull()) printf("Stack is full.\n");
                else printf("Stack is not full.\n");
                break;
            case 5: display(); break;
            case 6: peek(); break;
            case 7: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}


//Q2
//Write a program to reverse a string using stack.
#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];   //stack of characters (global variable)
int top = -1;      //top of the stack (global variable)

// Push a character onto the stack
void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
    } else {
        stack[++top] = c;
    }
}

// Pop a character from the stack
void pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
    } else {
        putchar(stack[top--]);
    }
}

//MAIN FUNCTION FOR Q2
int main() {
    char str[MAX];
    printf("Enter a string: ");
    fgets(str, MAX, stdin);  // (For simplicity; use fgets in practice)

    // Push all characters of the string onto the stack
    for (int i = 0; i < strlen(str); i++) {
        push(str[i]);
    }
}

//Q3
#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];   //stack of characters (global variable)
int top = -1;      //top of the stack (global variable)

// Push function
void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
    } else {
        stack[++top] = c;
    }
}

// Pop function
void pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
    } else {
        putchar(stack[top--]);
    }
}

// Function to check if parentheses are balanced
int isBalanced(char exp[]) {
    for (int i = 0; i < strlen(exp); i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
        } 
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (top == -1)
                return 0; // Closing bracket before opening

            pop();
            if ((exp[i] == ')' && stack[top] != '(') ||
                (exp[i] == '}' && stack[top] != '{') ||
                (exp[i] == ']' && stack[top] != '[')) {
                return 0; // Mismatched pair
            }
        }
    }

    // If stack is empty at the end, it's balanced
    return (top == -1);
}

int main() {
    char exp[MAX];
    printf("Enter an expression: ");
    fgets(exp, MAX, stdin );  // (for simplicity; use fgets in practice)

    if (isBalanced(exp))
        printf("Expression has balanced parentheses.\n");
    else
        printf("Expression does NOT have balanced parentheses.\n");

    return 0;
}   

//Q4

#include <stdio.h>
#include <ctype.h>  // For isalnum()
#include <string.h>

#define MAX 100

char stack[MAX];   //stack of characters (global variable)
int top = -1;      //top of the stack (global variable)

// Push function
void push(char c) {
    if (top == MAX - 1)
        printf("Stack Overflow!\n");
    else
        stack[++top] = c;
}

// Pop function
void pop() {
    if (top == -1)
        printf("Stack Underflow!\n");
    else
        putchar(stack[top--]);
}

// Function to return precedence of operators
int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

// Function to convert Infix to Postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;

    while ((c = infix[i++]) != '\0') {
        if (isalnum(c)) { // Operand -> add to output
            postfix[j++] = c;
        } 
        else if (c == '(') {
            push(c);
        } 
        else if (c == ')') {
            while (top != -1 && stack[top] != '(')
                putchar(pop());
            pop(); // remove '('
        } 
        else { // Operator
            while (top != -1 && precedence(stack[top]) >= precedence(c))
                putchar(pop());
            push(c);
        }
    }

    // Pop remaining operators
    while (top != -1)
                putchar(pop());

    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    fgets(infix, MAX, stdin); // For simplicity; use fgets in practice

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

//Q5

#include <stdio.h>
#include <ctype.h>  // For isdigit()

#define MAX 100

char stack[MAX];
int top = -1;

// Push function
void push(int value) {
    if (top == MAX - 1)
        printf("Stack Overflow!\n");
    else
        stack[++top] = value;
}

// Pop function
void pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
    } else {
        putchar(stack[top--]);
    }
}

// Function to evaluate postfix expression
int evaluatePostfix(char exp[]) {
    int i = 0;  
    int val1, val2, result;

    while ((c = exp[i++]) != '\0') {
        if (isdigit(c)) {
            // Convert character to integer and push
            push(c - '0');
        } 
        else if (c == ' ' || c == '\t') {
            continue; // Ignore spaces
        } 
        else {
            // Operator encountered, pop two operands
            val2 = pop();
            val1 = pop();

            switch (c) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                case '^': {
                    result = 1;
                    for (int j = 0; j < val2; j++)
                        result *= val1;
                    break;
                }
                default:
                    printf("Invalid operator: %c\n", c);
                    return -1;
            }
            push(result);
        }
    }
    return pop(); // Final result
}

int main() {
    char exp[MAX];

    printf("Enter a postfix expression (e.g., 23*54*+9-): ");
    fgets(exp, MAX, stdin);  // For simplicity; use fgets in practice

    int result = evaluatePostfix(exp);
    printf("Result of Postfix Evaluation: %d\n", result);

    return 0;
}
