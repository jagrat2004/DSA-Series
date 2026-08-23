#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& num, int tar) {
    if (tar < 0)
        return 0;
    if (tar == 0)
        return 1;

    int ans = 0;
    for (int i = 0; i < num.size(); i++) {  
        ans += solve(num, tar - num[i]);
    }
    return ans;
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