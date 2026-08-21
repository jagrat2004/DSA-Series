#include<iostream>
#include<vector>
using namespace std;



void insertSortAlgo(int n, vector<int>&arr){
    for(int i = 1; i<n; i++){
        int temp = arr[i];
        int j = i-1;
        for(; j>=0; j--){
            if(arr[j] > temp){
                //shift
                arr[j+1] = arr[j];
            }else{
                break;
            }
        }
        arr[j+1] = temp;
    }
}

int main()
{
    vector<int> arr = {10, 1, 7, 4, 8, 2, 11, 6};

    int n = arr.size();

    insertSortAlgo(n, arr);

    cout << "Sorted array: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}