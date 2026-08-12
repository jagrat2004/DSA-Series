#include <bits/stdc++.h>
using namespace std;

int solve(int n, int x, int y, int z, vector<int>& dp) {
    if (n == 0)
        return 0;
    if (n < 0)
        return INT_MIN;
    if (dp[n] != -1)
        return dp[n];   // fixed: missing semicolon

    int a = solve(n - x, x, y, z, dp);
    int b = solve(n - y, x, y, z, dp);
    int c = solve(n - z, x, y, z, dp);

    // fixed: guard INT_MIN overflow before adding 1
    if (a != INT_MIN) a += 1;
    if (b != INT_MIN) b += 1;
    if (c != INT_MIN) c += 1;

    dp[n] = max(a, max(b, c));
    return dp[n];
}

int cutSegments(int n, int x, int y, int z) {
    vector<int> dp(n + 1, -1);
    int ans = solve(n, x, y, z, dp);
    if (ans < 0)
        return 0;
    else
        return ans;
}

int main() {
    int n, x, y, z;
    cout << "Enter total length (n): ";
    cin >> n;
    cout << "Enter segment lengths (x y z): ";
    cin >> x >> y >> z;

    cout << "Maximum number of segments: " << cutSegments(n, x, y, z) << endl;

    return 0;
}