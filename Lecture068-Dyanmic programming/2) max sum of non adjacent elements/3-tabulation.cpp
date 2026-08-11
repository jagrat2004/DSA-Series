#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums) {          
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];

    for (int i = 1; i < n; i++) {      
        int inclu = nums[i];
        if (i - 2 >= 0)                
            inclu += dp[i - 2];

        int exclu = dp[i - 1];         

        dp[i] = max(inclu, exclu);
    }

    return dp[n - 1];
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