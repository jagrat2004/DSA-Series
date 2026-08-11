#include <bits/stdc++.h>
using namespace std;

int solveTab(vector<int>& num, int x) {
    vector<int> dp(x + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= x; i++) {          // fixed: i starts from 1 (dp[0]=0 already set)
        for (int j = 0; j < num.size(); j++) {  // fixed: nums → num
            if (i - num[j] >= 0 && dp[i - num[j]] != INT_MAX) {
                dp[i] = min(dp[i], 1 + dp[i - num[j]]);
            }
        }
    }

    if (dp[x] == INT_MAX)
        return -1;
    return dp[x];
}

int minElements(vector<int>& num, int x) {
    return solveTab(num, x);
}

int main() {
    int x;
    cout << "Enter target value: ";
    cin >> x;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> num(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> num[i];

    int result = minElements(num, x);

    if (result == -1)
        cout << "Not possible to reach target " << x << endl;
    else
        cout << "Minimum elements needed: " << result << endl;

    return 0;
}