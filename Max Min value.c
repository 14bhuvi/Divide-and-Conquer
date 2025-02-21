#include <stdio.h>

void maxmin(int a[], int low, int high, int *min, int *max) {
    int mid, max1, min1;

    if (low == high) {
        *max = *min = a[low];
    } else if (low == high - 1) {
        if (a[low] > a[high]) {
            *max = a[low];
            *min = a[high];
        } else {
            *max = a[high];
            *min = a[low];
        }
    } else {
        mid = (low + high) / 2;
        
        maxmin(a, low, mid, min, max);
        maxmin(a, mid + 1, high, &min1, &max1);

        if (max1 > *max) {
            *max = max1;
        }
        if (min1 < *min) {
            *min = min1;
        }
    }
}

int main() {
    int i, n, min, max;
    int a[20];

    printf("Enter the size of an array: ");
    scanf("%d", &n);

    if (n > 20 || n <= 0) { 
        printf("Invalid array size. Please enter a size between 1 and 20.\n");
        return 1;
    }

    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    maxmin(a, 0, n - 1, &min, &max);

    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);

    return 0;
}
