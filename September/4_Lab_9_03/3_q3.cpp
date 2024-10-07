#include <stdio.h>
#include <stdlib.h>

// Function to read sorted array from a file
int* readArrayFromFile(const char *filename, int *size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }

    // Read the size of the array
    fscanf(file, "%d", size);
    int *array = (int *)malloc(*size * sizeof(int));
    if (array == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }

    // Read the elements of the array
    for (int i = 0; i < *size; i++) {
        fscanf(file, "%d", &array[i]);
    }

    fclose(file);
    return array;
}

// Function to merge three sorted arrays into a single sorted array
int* mergeThreeSortedArrays(int *arr1, int size1, int *arr2, int size2, int *arr3, int size3, int *mergedSize) {
    *mergedSize = size1 + size2 + size3;
    int *mergedArray = (int *)malloc(*mergedSize * sizeof(int));
    if (mergedArray == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }

    int i = 0, j = 0, k = 0, index = 0;

    // Merge the arrays until one of them is exhausted
    while (i < size1 && j < size2 && k < size3) {
        if (arr1[i] <= arr2[j] && arr1[i] <= arr3[k]) {
            mergedArray[index++] = arr1[i++];
        } else if (arr2[j] <= arr1[i] && arr2[j] <= arr3[k]) {
            mergedArray[index++] = arr2[j++];
        } else {
            mergedArray[index++] = arr3[k++];
        }
    }

    // Merge the remaining elements from arr1 and arr2
    while (i < size1 && j < size2) {
        mergedArray[index++] = (arr1[i] <= arr2[j]) ? arr1[i++] : arr2[j++];
    }

    // Merge the remaining elements from arr2
