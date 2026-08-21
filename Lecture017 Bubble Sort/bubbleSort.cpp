#include<vector>
#include<iostream>
using namespace std;

void bubbleSortAlgo(vector<int>&arr, int n){
    for(int i = 1; i<n; i++){
        //for round 1 to n-1
        bool swapped = false;

        for(int j = 0; j<n-1;j++){
            //process element till n-i th index
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(swapped == false){
            break;
        }
    }
}

int main()
{
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    int n = arr.size();

    bubbleSortAlgo(arr, n);

    cout << "Sorted array: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}
