#include <bits/stdc++.h>
using namespace std;

int solveMem(vector<int>& num, int x, vector<int>& dp) {
    if (x == 0)
        return 0;
    if (x < 0)
        return INT_MAX;

    if (dp[x] != -1)
        return dp[x];

    int mini = INT_MAX;
    for (int i = 0; i < num.size(); i++) {
        int ans = solveMem(num, x - num[i], dp);  
        if (ans != INT_MAX)
            mini = min(mini, 1 + ans);
    }
    dp[x] = mini;
    return mini;
}

int minimumElement(vector<int>& num, int x) {
    vector<int> dp(x + 1, -1);
    int ans = solveMem(num, x, dp);
    if (ans == INT_MAX)
        return -1;
    else
        return ans;
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

    int result = minimumElement(num, x);

    if (result == -1)
        cout << "Not possible to reach target " << x << endl;
    else
        cout << "Minimum elements needed: " << result << endl;

    return 0;
}