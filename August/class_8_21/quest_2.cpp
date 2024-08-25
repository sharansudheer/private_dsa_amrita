//Recursive Linear Search Algorithm

#include <stdio.h>

// Define a function to perform the linear search
int linearSearch(int arr[], int size, int key)
{
    // If the size of the array is zero, return -1
    if (size == 0) {
        return -1;
    }

    // Check if the element at the current index
    // is equal to the key
    if (arr[size - 1] == key) {
        
        // If equal, return the index
        return size - 1;
    }
    // If not equal, call the function again
    // with the size reduced by 1
    return linearSearch(arr, size - 1, key);
}
