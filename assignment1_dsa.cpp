// Assignment 1: DSA (ARRAYS)

//Q1

#include <stdio.h>

// Global array and its size
int arr[100];   // maximum 100 elements
int n = 0;      // current number of elements

// Function to create an array
void create() {
    int i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Array created successfully!\n");
}

// Function to display the array elements
void display() {
    int i;
    if (n == 0) {
        printf("Array is empty!\n");
        return;
    }

    printf("Array elements are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert an element
void insert() {
    int pos, val, i;
    if (n == 0) {
        printf("Array is empty. Please create the array first.\n");
        return;
    }

    printf("Enter position to insert (1 to %d): ", n + 1);
    scanf("%d", &pos);
    printf("Enter value to insert: ");
    scanf("%d", &val);

    if (pos < 1 || pos > n + 1) {
        printf("Invalid position!\n");
        return;
    }

    // Shift elements to the right
    for (i = n - 1; i >= pos - 1; i--) {
        arr[i + 1] = arr[i];
    }

    arr[pos - 1] = val;
    n++;  // increase size
    printf("Element inserted successfully!\n");
}

// Function to delete an element
void delete_element() {
    int pos, i;
    if (n == 0) {
        printf("Array is empty!\n");
        return;
    }

    printf("Enter position to delete (1 to %d): ", n);
    scanf("%d", &pos);

    if (pos < 1 || pos > n) {
        printf("Invalid position!\n");
        return;
    }

    // Shift elements to the left
    for (i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--;  // decrease size
    printf("Element deleted successfully!\n");
}

// Function to perform linear search
void linearSearch() {
    int val, i, found = 0;
    if (n == 0) {
        printf("Array is empty!\n");
        return;
    }

    printf("Enter value to search: ");
    scanf("%d", &val);

    for (i = 0; i < n; i++) {
        if (arr[i] == val) {
            printf("Element %d found at position %d\n", val, i + 1);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Element not found in the array.\n");
}

// Main function with menu
int main() {
    int choice;

    while (1) {
        printf("\n——MENU——\n");
        printf("1. CREATE\n");
        printf("2. DISPLAY\n");
        printf("3. INSERT\n");
        printf("4. DELETE\n");
        printf("5. LINEAR SEARCH\n");
        printf("6. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert();
            break;
        case 4:
            delete_element();
            break;
        case 5:
            linearSearch();
            break;
        case 6:
            printf("Exiting program...\n");
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
}


//Q2

#include <stdio.h>

void remove_duplicates() {
    int arr[100], n, i, j, k;

    // Step 1: Take input for array size
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Step 2: Input array elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 3: Logic to remove duplicates
    // Outer loop traverses each element
    for (i = 0; i < n; i++) {
        // Inner loop checks for duplicates ahead
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                // Shift all elements to the left
                for (k = j; k < n - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                n--;    // reduce size of array
                j--;    // adjust index after shifting
            }
        }
    }

    // Step 4: Display unique elements
    printf("Array after removing duplicates:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

//Q3

// ANSWER: 10000

//Q4
#include <stdio.h>

// Function to reverse an array
void reverseArray() {
    int arr[100], n, i, temp;

    printf("\nEnter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Logic to reverse array
    for (i = 0; i < n / 2; i++) {
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }

    printf("Reversed Array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function for matrix multiplication
void matrixMultiplication() {
    int a[10][10], b[10][10], result[10][10];
    int r1, c1, r2, c2;
    int i, j, k;

    printf("\nEnter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("Matrix multiplication not possible! (Columns of A != Rows of B)\n");
        return;
    }

    printf("Enter elements of first matrix (A):\n");
    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            scanf("%d", &a[i][j]);

    printf("Enter elements of second matrix (B):\n");
    for (i = 0; i < r2; i++)
        for (j = 0; j < c2; j++)
            scanf("%d", &b[i][j]);

    // Initialize result matrix to 0
    for (i = 0; i < r1; i++)
        for (j = 0; j < c2; j++)
            result[i][j] = 0;

    // Matrix multiplication logic
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            for (k = 0; k < c1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("Resultant Matrix (A x B):\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++)
            printf("%d ", result[i][j]);
        printf("\n");
    }
}

// Function to find transpose of a matrix
void matrixTranspose() {
    int a[10][10], transpose[10][10];
    int r, c, i, j;

    printf("\nEnter rows and columns of matrix: ");
    scanf("%d %d", &r, &c);

    printf("Enter elements of the matrix:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &a[i][j]);

    // Transpose logic
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            transpose[j][i] = a[i][j];

    printf("Transpose of the matrix:\n");
    for (i = 0; i < c; i++) {
        for (j = 0; j < r; j++)
            printf("%d ", transpose[i][j]);
        printf("\n");
    }
}

// Main function with menu
void matrix_menu() {
    int choice;

    while (1) {
        printf("\n—— MENU ——\n");
        printf("1. Reverse Array\n");
        printf("2. Matrix Multiplication\n");
        printf("3. Transpose of Matrix\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            reverseArray();
            break;
        case 2:
            matrixMultiplication();
            break;
        case 3:
            matrixTranspose();
            break;
        case 4:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
}


//Q5

#include <stdio.h>

void matrix_sum() {
    int a[10][10];
    int row, col;
    int i, j;

    // Step 1: Take matrix size input
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &row, &col);

    // Step 2: Input elements of the matrix
    printf("Enter elements of the matrix:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Step 3: Display the matrix
    printf("\nMatrix:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    // Step 4: Calculate sum of each row
    printf("\nSum of each row:\n");
    for (i = 0; i < row; i++) {
        int rowSum = 0;
        for (j = 0; j < col; j++) {
            rowSum += a[i][j];
        }
        printf("Row %d = %d\n", i + 1, rowSum);
    }

    // Step 5: Calculate sum of each column
    printf("\nSum of each column:\n");
    for (j = 0; j < col; j++) {
        int colSum = 0;
        for (i = 0; i < row; i++) {
            colSum += a[i][j];
        }
        printf("Column %d = %d\n", j + 1, colSum);
    }


}
