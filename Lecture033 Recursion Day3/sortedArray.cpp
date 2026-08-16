#include<iostream>
using namespace std;

bool isSort(int arr[], int size){
    if(size == 0 || size == 1){
        return true;
    }
    if(arr[0] > arr[1])
     return false;

    else{
        return isSort(arr+1, size-1);
    }
}

int main() {

    int arr[5] = {2,4,10,9,9};
    int size = 5;

    bool ans = isSort(arr, size);

    if(ans){
        cout << "Array is sorted " << endl;
    }
    else {
        cout << "Array is not sorted " << endl;
    }

    return 0;
}