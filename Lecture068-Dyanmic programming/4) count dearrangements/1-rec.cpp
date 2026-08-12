#include <bits/stdc++.h>
using namespace std;

const long long int MOD = 1e9 + 7;   

long long int countDerangements(int n) {  
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    long long int ans = ((long long int)(n - 1) % MOD *    
                        ((countDerangements(n - 1) % MOD +
                          countDerangements(n - 2) % MOD) % MOD)) % MOD;
    return ans;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Number of Derangements: " << countDerangements(n) << endl;

    return 0;
}