#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& num, int tar) {
    vector<int> dp(tar + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= tar; i++) {
        for (int j = 0; j < num.size(); j++) {
            if (i - num[j] >= 0)           
                dp[i] += dp[i - num[j]];
        }
    }
    return dp[tar];
}

int findWays(vector<int>& num, int tar) {
    return solve(num, tar);
}

int main() {
    int n, target;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> num(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> num[i];

    cout << "Enter target: ";
    cin >> target;

    int result = findWays(num, target);
    cout << "Number of ways to reach target: " << result << endl;

    return 0;
}