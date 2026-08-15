#include <iostream>
#include <vector>
using namespace std;

// 1. Plain Recursion - O(2^n) time, O(n) space
int fibRecursion(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibRecursion(n - 1) + fibRecursion(n - 2);
}

// 2. Memoization - O(n) time, O(n) space
int fibMemo(int n, vector<int>& dp) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (dp[n] != -1) return dp[n];
    dp[n] = fibMemo(n - 1, dp) + fibMemo(n - 2, dp);
    return dp[n];
}

// 3. Tabulation - O(n) time, O(n) space
int fibTab(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}

// 4. Space Optimized - O(n) time, O(1) space
int fibOptimized(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    int prev2 = 0;
    int prev1 = 1;
    for (int i = 2; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    // Recursion
    cout << "Recursion   : " << fibRecursion(n) << endl;

    // Memoization
    vector<int> dp(n + 1, -1);
    cout << "Memoization : " << fibMemo(n, dp) << endl;

    // Tabulation
    cout << "Tabulation  : " << fibTab(n) << endl;

    // Space Optimized
    cout << "Optimized   : " << fibOptimized(n) << endl;

    return 0;
}