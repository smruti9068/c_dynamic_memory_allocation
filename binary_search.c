#include <stdio.h>
#include <stdlib.h>

// Function to perform binary search
int binarySearch(int *array, int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the target is present at mid
        if (array[mid] == target) {
            return mid; // Target found
        }

        // If target is greater, ignore the left half
        if (array[mid] < target) {
            left = mid + 1;
        } else {
            // If target is smaller, ignore the right half
            right = mid - 1;
        }
    }

    return -1; // Target not found
}

int main() {
    int *array;
    int size, target, result;

    // Input the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    // Dynamically allocate memory for the array
    array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit if memory allocation fails
    }

    // Input the sorted array elements
    printf("Enter %d sorted elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    // Input the target element to search for
    printf("Enter the element to search for: ");
    scanf("%d", &target);

    // Perform binary search
    result = binarySearch(array, size, target);

    // Output the result
    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    // Free the dynamically allocated memory
    free(array);

    return 0;
}