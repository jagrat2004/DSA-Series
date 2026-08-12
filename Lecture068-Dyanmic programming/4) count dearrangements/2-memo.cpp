#include <bits/stdc++.h>
using namespace std;

const long long int MOD = 1e9 + 7;  

long long int solve(int n, vector<long long int>&dp) {  
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    if(dp[n] != -1)
     return dp[n];

    dp[n] = ((long long int)(n - 1) % MOD *    
                        ((solve(n - 1,dp) % MOD +
                          solve(n - 2,dp) % MOD) % MOD)) % MOD;
    return dp[n];
}


long long int countDerangements(int n) {  
    vector<long long int>dp(n+1, -1);
    return solve(n,dp);
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Number of Derangements: " << countDerangements(n) << endl;

    return 0;
}