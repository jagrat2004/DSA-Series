#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long int add(long long int a, long long int b) {  
    return ((a % MOD) + (b % MOD)) % MOD;
}

long long int mul(long long int a, long long int b) {  
    return ((a % MOD) * (b % MOD)) % MOD;
}

long long int solve(int n, int k, vector<long long int>&dp) {
    if (n == 1)                                        
        return k;
    if (n == 2)                                        
        return add(k, mul(k, k - 1));

    if(dp[n] != -1)
     return dp[n];

    dp[n] = add(mul(solve(n - 2, k, dp), k - 1),
                            mul(solve(n - 1, k,dp), k - 1));  
    return dp[n];
}

long long int numberOfWays(int n, int k) {
    vector<long long int>dp(n+1, -1);
    return solve(n, k, dp);
}

int main() {
    int n, k;
    cout << "Enter number of posts (n): ";
    cin >> n;
    cout << "Enter number of colors (k): ";
    cin >> k;

    cout << "Number of Ways: " << numberOfWays(n, k) << endl;

    return 0;
}