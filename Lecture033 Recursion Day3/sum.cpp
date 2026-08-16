#include<iostream>
using namespace std;


int SumOfArray(int *arr, int size){
    if(size == 0){
        return 0;
    }
    if(size == 1){
        return arr[0];
    }
    int nextPart = SumOfArray(arr+1, size-1);
    int sum = arr[0] + nextPart;
    return sum;
}

int main() {

    int arr[5] = {2,4,2,2,6};
    int size = 5;

    int sum = SumOfArray(arr, size);

    cout << "Sum is " << sum << endl;

    return 0;
}