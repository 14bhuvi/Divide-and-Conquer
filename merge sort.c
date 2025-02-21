#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int low, int mid, int high) {
    int b[high - low + 1];  // Temporary array
    int h = low, i = 0, j = mid + 1;
    
    // Merging process
    while (h <= mid && j <= high) {
        if (a[h] < a[j]) {
            b[i] = a[h];
            h++;
        } else {
            b[i] = a[j];
            j++;
        }
        i++;
    }
    
    // Copy remaining elements from left half
    while (h <= mid) {
        b[i] = a[h];
        h++;
        i++;
    }

    // Copy remaining elements from right half
    while (j <= high) {
        b[i] = a[j];
        j++;
        i++;
    }

    // Copy back sorted elements into original array
    for (i = 0, h = low; h <= high; i++, h++) {
        a[h] = b[i];
    }
}

void mergesort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main() {
    int a[10], n, i;

    printf("Enter the size of array (max 10): ");
    scanf("%d", &n);

    if (n <= 0 || n > 10) {
        printf("Invalid size. Enter a number between 1 and 10.\n");
        return 1;
    }

    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Before merge sort: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    mergesort(a, 0, n - 1);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
