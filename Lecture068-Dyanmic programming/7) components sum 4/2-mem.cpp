#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& num, int tar, vector<int>& dp) {
    if (tar < 0)
        return 0;
    if (tar == 0)
        return 1;

    if(dp[tar] != -1){
        return dp[tar];
    }

    int ans = 0;
    for (int i = 0; i < num.size(); i++) {  
        ans += solve(num, tar - num[i], dp);
    }
    dp[tar] = ans;
    return dp[tar];
}

int findWays(vector<int>& num, int tar) {
    vector<int>dp(tar+1, -1);
    return solve(num, tar, dp);
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