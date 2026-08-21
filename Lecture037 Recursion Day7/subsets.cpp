#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void solve(vector<int> nums, vector<int> output, int index,
               vector<vector<int>>& ans) {

        // Base case
        if (index >= nums.size()) {
            ans.push_back(output);
            return;
        }

        // Exclude current element
        solve(nums, output, index + 1, ans);

        // Include current element
        int element = nums[index];
        output.push_back(element);

        solve(nums, output, index + 1, ans);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;

        solve(nums, output, index, ans);

        return ans;
    }
};

int main() {
    Solution obj;

    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<vector<int>> ans = obj.subsets(nums);

    // Print all subsets
    for (const auto& subset : ans) {
        cout << "[";
        
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i];

            if (i != subset.size() - 1)
                cout << ",";
        }

        cout << "]" << endl;
    }

    return 0;
}