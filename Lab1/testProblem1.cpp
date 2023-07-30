#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// function prototypes
void input(int* arr, int n);
void print(int* arr, int n);
void removeOdd(int* &arr, int &n);

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int* arr = new int[n];
    input(arr, n);
    cout << "The original array is: ";
    print(arr, n);

    removeOdd(arr, n);
    cout << "The updated array with odd numbers removed is: ";
    print(arr, n);

    delete[] arr;
    return 0;
}

// function to input random numbers
void input(int* arr, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        *(arr + i) = rand() % 100; // generates random numbers between 0 and 99
    }
}

// function to print the array
void print(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

// function to remove odd numbers from the array
void removeOdd(int* &arr, int &n) {
    int* temp = new int[n];
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (*(arr + i) % 2 == 0) { // even number
            *(temp + count) = *(arr + i);
            count++;
        }
    }
    delete[] arr;
    arr = temp;
    n = count;
}

