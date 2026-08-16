#include<iostream>
using namespace std;

void print(int arr[], int s, int e){
    for(int i =s; i<=e; i++){
        cout << arr[i] << " ";
    } cout << endl;
}



bool binarySearchInd(int *arr, int s, int e, int k){
    if(s>e)
     return false;

    int mid = s + (e-s)/2;

    if(arr[mid] == k)
     return true;

    if(arr[mid] < k){
        return binarySearchInd(arr, mid+1, e, k);
   }else{
      return binarySearchInd(arr,s,mid-1,k);
   }
}


int main() {

    int arr[11] = {2,4,6,10,14,18,22,38,49,55,222};
    int size = 11;
    int key = 223;

    cout << "Present or not " << binarySearchInd(arr, 0, size-1, key) << endl;

    return 0;
}