#include <iostream>
#include <vector>
using namespace std;

// 1. Plain Recursion - O(2^n) time, O(n) space
int countDistinctWayToClimbStair(long long nStairs) {
    if (nStairs < 0) return 0;
    if (nStairs == 0) return 1;

    return countDistinctWayToClimbStair(nStairs - 1) +
           countDistinctWayToClimbStair(nStairs - 2);
}

// 2. Memoization - O(n) time, O(n) space
int countMemo(long long nStairs, vector<int>& dp) {
    if (nStairs < 0) return 0;
    if (nStairs == 0) return 1;
    if (dp[nStairs] != -1) return dp[nStairs];

    dp[nStairs] = countMemo(nStairs - 1, dp) + countMemo(nStairs - 2, dp);
    return dp[nStairs];
}

// 3. Tabulation - O(n) time, O(n) space
int countTab(long long nStairs) {
    if (nStairs == 0) return 1;
    if (nStairs == 1) return 1;

    vector<int> dp(nStairs + 1, 0);
    dp[0] = 1;   // 1 way to stay at ground
    dp[1] = 1;   // 1 way to climb 1 stair

    for (int i = 2; i <= nStairs; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[nStairs];
}

// 4. Space Optimized - O(n) time, O(1) space
int countOptimized(long long nStairs) {
    if (nStairs == 0) return 1;
    if (nStairs == 1) return 1;

    int prev2 = 1;   // dp[0]
    int prev1 = 1;   // dp[1]

    for (int i = 2; i <= nStairs; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main() {
    long long n;
    cout << "Enter number of stairs: ";
    cin >> n;

    cout << "Recursion   : " << countDistinctWayToClimbStair(n) << endl;

    vector<int> dp(n + 1, -1);
    cout << "Memoization : " << countMemo(n, dp) << endl;

    cout << "Tabulation  : " << countTab(n) << endl;

    cout << "Optimized   : " << countOptimized(n) << endl;

    return 0;
}