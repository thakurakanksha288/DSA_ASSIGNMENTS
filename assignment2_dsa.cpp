//ASSIGNMENT 2: ARRAYS

//Q1

#include <iostream>
using namespace std;

// Function to perform Binary Search
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid; // Key found, return index
        else if (arr[mid] < key)
            low = mid + 1; // Search in right half
        else
            high = mid - 1; // Search in left half
    }

    return -1; // Key not found
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    cout << "Enter element to search: ";
    cin >> key;

    int result = binarySearch(arr, n, key);

    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found in the array." << endl;

    return 0;
}

//Q2
#include <iostream>
using namespace std;

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Last i elements are already sorted
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
//MAIN FUNCTION FOR Q2
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    bubbleSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
//Q3
#include <iostream>
using namespace std;

// Function to find missing number in a linear array
int findMissingLinear(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != i + 1)
            return i + 1;  // Missing number found
    }
    return n; // If all elements are correct, missing is last number
}

//MAIN FUNCTION FOR Q3
int main() {
    int arr[] = {1, 2, 3, 4, 6, 7, 8};
    int n = 8; // Should be 1 to 8 (but array has 7 elements)
    
    cout << "Missing number (Linear): " << findMissingLinear(arr, n) << endl;
    return 0;
}

//Q4
    //(a) Write a program to concatenate one string to another string.
#include <iostream>
using namespace std;

// Function to concatenate two strings
void concatenateStrings(const string& str1, const string& str2) {
    cout << "Concatenated string: " << str1 + str2 << endl;
}

//MAIN FUNCTION FOR Q4(a)
int main() {
    string str1 = "Hello, ";
    string str2 = "World!";
    concatenateStrings(str1, str2);
    return 0;
}

//(b) Write a program to reverse a string.
#include <iostream>
using namespace std;

// Function to reverse a string
void reverseString(string& str) {
    reverse(str.begin(), str.end());
}           

//MAIN FUNCTION FOR Q4(b)
int main() {
    string str = "Hello, World!";
    reverseString(str);
    cout << "Reversed string: " << str << endl;
    return 0;
}

//(c) Write a program to delete all the vowels from the string.
#include <iostream>
using namespace std;

// Function to delete all the vowels from the string
void deleteVowels(string& str) {
    str.erase(remove_if(str.begin(), str.end(), [](char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }), str.end());
}

//MAIN FUNCTION FOR Q4(c)
int main() {
    string str = "Hello, World!";               
    deleteVowels(str);
    cout << "String without vowels: " << str << endl;
    return 0;
}

//(d) Write a program to sort the strings in alphabetical order.
#include <iostream>
using namespace std;

// Function to sort the strings in alphabetical order
void sortStrings(string& str) {
    sort(str.begin(), str.end());  
}

//MAIN FUNCTION FOR Q4(d)
int main() {
    string str = "Hello, World!";
    sortStrings(str);
    cout << "Sorted string: " << str << endl;
    return 0;
}

//(e) Write a program to convert a character from uppercase to lowercase.
#include <iostream>
using namespace std;

// Function to convert a character from uppercase to lowercase
void convertToLowercase(char& c) {
    c = tolower(c);
}

//MAIN FUNCTION FOR Q4(e)
int main() {
    char c = 'A';
    convertToLowercase(c);
    cout << "Converted character: " << c << endl;
    return 0;
}

//Q5
#include <iostream>
using namespace std;

class DiagonalMatrix {
    int *A;
    int n;

public:
    DiagonalMatrix(int n) {
        this->n = n;
        A = new int[n];
    }

    void set(int i, int j, int x) {
        if (i == j)
            A[i - 1] = x;
    }

    int get(int i, int j) {
        if (i == j)
            return A[i - 1];
        else
            return 0;
    }

    void display() {
        for (int i = 1; i <= n; i++) {   //display the matrix
            for (int j = 1; j <= n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }

    ~DiagonalMatrix() {
        delete[] A;
    }       //destructor
};

//MAIN FUNCTION FOR Q5
int main() {
    DiagonalMatrix m(3);
    m.set(1, 1, 1);
    m.set(2, 2, 2);
    m.set(3, 3, 3);
    m.display();
    return 0;
}


//Q6

#include <iostream>
using namespace std;

#define MAX 100

struct Term {
    int row;
    int col;
    int val;
};

class SparseMatrix {
public:
    Term data[MAX];
    int rows, cols, terms;

    void readMatrix() {
        cout << "Enter number of rows, columns, and non-zero elements: ";
        cin >> rows >> cols >> terms;

        cout << "Enter row, column, and value of each non-zero element:\n";
        for (int i = 0; i < terms; i++) {
            cin >> data[i].row >> data[i].col >> data[i].val;
        }
    }

    void display() {
        cout << "Row\tCol\tVal\n";
        for (int i = 0; i < terms; i++) {
            cout << data[i].row << "\t" << data[i].col << "\t" << data[i].val << "\n";
        }
    }

    // (a) Transpose
    SparseMatrix transpose() {
        SparseMatrix result;
        result.rows = cols;
        result.cols = rows;
        result.terms = terms;

        int k = 0;
        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < terms; j++) {
                if (data[j].col == i) {
                    result.data[k].row = data[j].col;
                    result.data[k].col = data[j].row;
                    result.data[k].val = data[j].val;
                    k++;
                }
            }
        }
        return result;
    }

    // (b) Addition
    SparseMatrix add(SparseMatrix b) {
        SparseMatrix sum;
        if (rows != b.rows || cols != b.cols) {
            cout << "Addition not possible (different dimensions)\n";
            sum.terms = 0;
            return sum;
        }

        int i = 0,
        j = 0,
        k = 0;

        while (i < terms && j < b.terms) {
            if (data[i].row < b.data[j].row || (data[i].row == b.data[j].row && data[i].col < b.data[j].col)) {
                sum.data[k] = data[i];
                i++;
                k++;
            }
            else if (data[i].row > b.data[j].row || (data[i].row == b.data[j].row && data[i].col > b.data[j].col)) {
                sum.data[k] = b.data[j];
                j++;
                k++;        
            }
            else {
                sum.data[k] = data[i];
                sum.data[k].val += b.data[j].val;
                i++;
                j++;
                k++;
            }
        }
        while (i < terms) {
            sum.data[k] = data[i];
            i++; 
            k++;
        }
        while (j < b.terms) {
            sum.data[k] = b.data[j];
            j++;
            k++;
        }
        return sum;
    }
};  
//MAIN FUNCTION FOR Q6
int main() {
    SparseMatrix m;
    m.readMatrix();
    m.display();
    return 0;
}

//Q7
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int A[n];

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] > A[j])
                count++;
        }
    }

    cout << "Number of inversions = " << count << endl;
    return 0;
}


//Q8

#include <iostream>
#include <set>   // to store unique elements
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    set<int> distinct;  // Set automatically keeps only unique elements
    for (int i = 0; i < n; i++)
        distinct.insert(arr[i]);

    cout << "Total number of distinct elements = " << distinct.size() << endl;
    return 0;
}
