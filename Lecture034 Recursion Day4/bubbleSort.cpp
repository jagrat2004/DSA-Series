#include<iostream>
using namespace std;


void sortedArr(int *arr, int n){

    //base case - already sorted
    if(n == 0|| n==1){
        return ;
    }

    //1 case sovle karlia - largest element ko end me rakh dega
    for(int i = 0; i<n-1; i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }
    sortedArr(arr, n-1);
}

int main() {

    int arr[6] = {2,5,1,6,9,3};
    
    sortedArr(arr,6);

    for(int i=0; i<6; i++) {
        cout << arr[i] << " ";
    }cout << endl;


    return 0;
}