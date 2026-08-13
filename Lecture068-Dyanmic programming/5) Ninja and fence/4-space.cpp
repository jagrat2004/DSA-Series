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
   if(n==1) return k;
   if(n == 2) return add(k,mul(k,k-1));

   long long int prev2 = k;
   long long int prev1 = add(k,mul(k,k-1));

   for(int i = 3; i<=n; i++){
    long long int curr = add(mul(prev2, k-1), mul(prev1, k-1));
    prev2 = prev1;
    prev1 = curr;
   }
   return prev1;

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