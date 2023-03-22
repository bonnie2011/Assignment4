#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int extraMemoryAllocated;

// implement merge sort
// extraMemoryAllocated counts bytes of extra memory allocated

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// implement insertion sort
// extraMemoryAllocated counts bytes of memory allocated
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// implement bubble sort
// extraMemoryAllocated counts bytes of extra memory allocated
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// implement selection sort
// extraMemoryAllocated counts bytes of extra memory allocated
void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
        extraMemoryAllocated += 2 * sizeof(int);
    }
}

// parses input file to an integer array


// prints first and last 100 items in the data array

int main() {
int n = 10000;
int arr[n];
srand(time(0));
// initialize array with random values
for (int i = 0; i < n; i++)
    arr[i] = rand() % 100;

// merge sort
extraMemoryAllocated = 0;
clock_t tStart = clock();
mergeSort(arr, 0, n - 1);
printf("Merge sort: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
printf("Extra memory allocated: %d bytes\n", extraMemoryAllocated);

// insertion sort
extraMemoryAllocated = 0;
tStart = clock();
insertionSort(arr, n);
printf("Insertion sort: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
printf("Extra memory allocated: %d bytes\n", extraMemoryAllocated);

// bubble sort
extraMemoryAllocated = 0;
tStart = clock();
bubbleSort(arr, n);
printf("Bubble sort: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
printf("Extra memory allocated: %d bytes\n", extraMemoryAllocated);

// selection sort
extraMemoryAllocated = 0;
tStart = clock();
selectionSort(arr, n);
printf("Selection sort: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
printf("Extra memory allocated: %d bytes\n", extraMemoryAllocated);

return 0;
}
