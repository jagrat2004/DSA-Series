#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long int add(long long int a, long long int b) {  
    return ((a % MOD) + (b % MOD)) % MOD;
}

long long int mul(long long int a, long long int b) {  
    return ((a % MOD) * (b % MOD)) % MOD;
}

long long int solve(int n, int k) {
    if (n == 1)                                        
        return k;
    if (n == 2)                                        
        return add(k, mul(k, k - 1));

    long long int ans = add(mul(solve(n - 2, k), k - 1),
                            mul(solve(n - 1, k), k - 1));  
    return ans;
}

long long int numberOfWays(int n, int k) {
    return solve(n, k);
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