#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// Function to find the next smaller element for each element in the array
vector<int> nextSmallerElement(vector<int>& arr, int n) {
    stack<int> s;
    s.push(-1);  // No smaller element initially

    vector<int> ans(n);

    // Traverse the array from right to left
    for(int i = n - 1; i >= 0; i--) {
        int curr = arr[i];

        // Pop elements that are greater than or equal to current
        while(s.top() >= curr) {
            s.pop();
        }

        // The top of the stack is the next smaller element
        ans[i] = s.top();

        // Push current element to stack
        s.push(curr);
    }

    return ans;
}

int main() {
    vector<int> arr = {2, 1, 4, 3};
    int n = arr.size();

    vector<int> result = nextSmallerElement(arr, n);

    cout << "Next smaller elements:\n";
    for(int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
