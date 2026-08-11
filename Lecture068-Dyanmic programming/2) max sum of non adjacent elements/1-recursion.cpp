#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums, int n) {
    if (n < 0)
        return 0;
    if (n == 0)
        return nums[0];

    int include = solve(nums, n - 2) + nums[n];
    int exclude = solve(nums, n - 1) + 0;
    return max(include, exclude);  
}

int maxNonAdjSum(vector<int>& nums) {
    int n = nums.size();
    int ans = solve(nums, n - 1);
    return ans;
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