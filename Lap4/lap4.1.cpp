#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SIZE = 1000;

void inputArray(int arr[], int size) {
    cout << "Enter " << size << " integer(s): ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void outputArray(int arr[], int size) {
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Insertion sort
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
	
	int n;
	cin>>n;
    int arr[SIZE];

    srand(time(0));

    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 10000 + 1;
    }

    outputArray(arr, SIZE);

    insertionSort(arr, SIZE);

    outputArray(arr, SIZE);

    return 0;
}

