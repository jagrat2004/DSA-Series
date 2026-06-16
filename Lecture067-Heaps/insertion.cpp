#include<iostream>            // Bring in standard I/O stream facilities (cout, endl, etc.)
using namespace std;          // So we can write cout instead of std::cout

class heap{                   // Define a class named 'heap' to implement a Max Heap
    public:                   // Public members/methods accessible from outside the class
    int arr[100];             // Fixed-size array to store heap elements (we'll use 1-based indexing)
    int size;                 // Number of elements currently in the heap

    heap(){                   // Constructor: runs when a heap object is created
        arr[0] = -1;          // Sentinel/dummy value at index 0 (unused) to simplify parent/child math
        size = 0;             // Start with an empty heap
    }

    void insert(int val){     // Insert a value into the Max Heap
        size = size + 1;      // Increase heap size (new element added)
        int index = size;     // 'index' is the position where the new value goes (initially the last leaf)
        arr[index] = val;     // Place the new value at the end

        while(index > 1){                 // While the node is not the root
            int parent = index/2;         // Parent index in a 1-based heap
            if(arr[parent] < arr[index]){ // If parent is smaller, heap property is violated
                swap(arr[parent] , arr[index]); // Swap child with parent to restore order
                index = parent;           // Move up and continue "bubbling up"
            }else{                        // Otherwise, heap property satisfied at this path
                return;                   // Early exit: no more fixes needed
            }
        }
    }

    void print(){              // Print the heap in its array (level-order) form
        for(int i = 1; i <= size; i++){   // Start at 1 to skip the dummy at index 0
            cout << arr[i] << " ";        // Print each element followed by a space
        }
        cout<<endl;                        // Newline after printing all elements
    }
};

int main(){                    // Program entry point
    heap h;                    // Create a heap instance (initially empty)
    h.insert(50);              // Insert 50
    h.insert(55);              // Insert 55 (will bubble up to root since 55 > 50)
    h.insert(53);              // Insert 53
    h.insert(52);              // Insert 52 (may swap with its parent if needed)
    h.insert(54);              // Insert 54 (may bubble up under 55)
    h.print();                 // Print the heap array representation (level order)
    return 0;                  // Return success status (optional in modern C++)
}
