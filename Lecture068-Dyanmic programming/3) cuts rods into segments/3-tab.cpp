#include <bits/stdc++.h>
using namespace std;

int solve(int n, int x, int y, int z) {
    vector<int> dp(n + 1, INT_MIN);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {          
        if (i - x >= 0 && dp[i-x] != INT_MIN)  
            dp[i] = max(dp[i], dp[i-x] + 1);
        if (i - y >= 0 && dp[i-y] != INT_MIN)  
            dp[i] = max(dp[i], dp[i-y] + 1);
        if (i - z >= 0 && dp[i-z] != INT_MIN)  
            dp[i] = max(dp[i], dp[i-z] + 1);
    }

    if (dp[n] < 0)
        return 0;
    else
        return dp[n];
}

int cutSegments(int n, int x, int y, int z) {
    return solve(n, x, y, z);
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