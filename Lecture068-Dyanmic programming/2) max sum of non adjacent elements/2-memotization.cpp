#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums, int n, vector<int>&dp) {
    if (n < 0)
        return 0;
    if (n == 0)
        return nums[0];
    if(dp[n] != -1)
     return dp[n];

    int include = solve(nums, n - 2,dp) + nums[n];
    int exclude = solve(nums, n - 1,dp) + 0;
    dp[n]=max(include, exclude); 
    return dp[n]; 
}

int maxNonAdjSum(vector<int>& nums) {
    int n = nums.size();
    vector<int>dp(n,-1);
    return solve(nums, n - 1,dp);
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