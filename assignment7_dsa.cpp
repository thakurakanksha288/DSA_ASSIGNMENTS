//Q1


#include <iostream>
using namespace std;

// --------------------- SELECTION SORT ---------------------
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[minIndex], arr[i]);
    }
}

// --------------------- INSERTION SORT ---------------------
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// --------------------- BUBBLE SORT ---------------------
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }
}

// --------------------- MERGE SORT ---------------------
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int a[n1], b[n2];
    for (int i = 0; i < n1; i++) a[i] = arr[left + i];
    for (int i = 0; i < n2; i++) b[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (a[i] <= b[j])
            arr[k++] = a[i++];
        else
            arr[k++] = b[j++];
    }
    while (i < n1) arr[k++] = a[i++];
    while (j < n2) arr[k++] = b[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

// --------------------- QUICK SORT ---------------------
int partitionFunc(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partitionFunc(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// --------------------- PRINT FUNCTION ---------------------
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// --------------------- MAIN FUNCTION ---------------------
int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Original Array: ";
    printArray(arr, n);

    // Uncomment any one to test:

    //selectionSort(arr, n);
    //insertionSort(arr, n);
    //bubbleSort(arr, n);
    //mergeSort(arr, 0, n-1);
    //quickSort(arr, 0, n-1);

    cout << "Sorted Array: ";
    printArray(arr, n);

    return 0;
}



//Q2

#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n) {
    int left = 0;          // starting index
    int right = n - 1;     // ending index

    while (left < right) {

        int minIndex = left;
        int maxIndex = right;

        // If elements at boundary are out of order, swap them first
        if (arr[minIndex] > arr[maxIndex])
            swap(arr[minIndex], arr[maxIndex]);

        // find min and max in remaining middle array
        for (int i = left + 1; i < right; i++) {

            if (arr[i] < arr[minIndex])
                minIndex = i;

            else if (arr[i] > arr[maxIndex])
                maxIndex = i;
        }

        // Place minimum at correctness
        swap(arr[left], arr[minIndex]);

        // If maximum element was placed at left position, update its index
        if (maxIndex == left)
            maxIndex = minIndex;

        // Place maximum element at correctness
        swap(arr[right], arr[maxIndex]);

        left++;
        right--;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {10, 3, 15, 7, 8, 23, 74, 18};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    improvedSelectionSort(arr, n);

    cout << "Sorted array:   ";
    printArray(arr, n);

    return 0;
}
