#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums) {          
    int n = nums.size();
    int prev2 = 0;
    int prev1 = nums[0];
    for(int i = 1; i<n; i++){
        int inclu = prev2 + nums[i];
        int exclu = prev1;
        int ans = max(inclu,exclu);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}


int maxNonAdjSum(vector<int>& nums) {
    
    return solve(nums);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << "Maximum Non-Adjacent Sum: " << maxNonAdjSum(nums) << endl;

    return 0;
}