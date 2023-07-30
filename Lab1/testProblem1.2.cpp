#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to input random numbers in array A
void input(int* A, int n) {
    srand(time(NULL)); // Initialize random number generator
    for (int i = 0; i < n; i++) {
        *(A + i) = rand() % 10+1; // Generate random integer between 0 and 99
    }
}

// Function to print out the array
void print(int* A, int n) {
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(A + i));
    }
    printf("\n");
}

// Function to remove all odd numbers from the array
void remove_odd(int* A, int* n) {
    int count = 0; // Counter for even numbers
    for (int i = 0; i < *n; i++) {
        if (*(A + i) % 2 == 0) { // Check if current element is even
            *(A + count) = *(A + i); // Move even element to front of array
            count++; // Increment counter for even numbers
        }
    }
    *n = count; // Update size of array to number of even elements
}

// Main function to test the program
int main() {
    int n = 10; // Size of array
    int A[n]; // Declare array using pointer
    input(A, n);
    print(A, n);
    remove_odd(A, &n);
    print(A, n);
    return 0;
}

