#include <iostream>
using namespace std;

class Heap {
public:
    int arr[100];  // array to store heap
    int size;      // current size of heap

    Heap() {
        arr[0] = -1; // dummy index (1-based indexing)
        size = 0;
    }

    // Function to insert values (optional, for testing)
    void insert(int val) {
        size++;
        int index = size;
        arr[index] = val;

        // Bubble up
        while (index > 1) {
            int parent = index / 2;
            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                return;
            }
        }
    }

    // Heapify function
    void heapify(int arr[], int n, int i) {
        int largest = i;
        int left = 2 * i;
        int right = 2 * i + 1;

        if (left <= n && arr[largest] < arr[left]) {
            largest = left;
        }
        if (right <= n && arr[largest] < arr[right]) {
            largest = right;
        }

        if (largest != i) {
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }

    // Build a max heap
    void buildHeap(int arr[], int n) {
        for (int i = n / 2; i > 0; i--) {
            heapify(arr, n, i);
        }
    }

    // Heap sort
    void heapsort(int arr[], int n) {
        int size = n;
        while (size > 1) {
            swap(arr[size], arr[1]); // move largest element to end
            size--;
            heapify(arr, size, 1);  // restore heap
        }
    }

    // Print array
    void printArray(int arr[], int n) {
        for (int i = 1; i <= n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap h;

    // Example array (1-based indexing, arr[0] unused)
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    cout << "Original array: ";
    h.printArray(arr, n);

    // Step 1: Build max heap
    h.buildHeap(arr, n);
    cout << "After building max heap: ";
    h.printArray(arr, n);

    // Step 2: Heap Sort
    h.heapsort(arr, n);
    cout << "After Heap Sort: ";
    h.printArray(arr, n);

    return 0;
}
