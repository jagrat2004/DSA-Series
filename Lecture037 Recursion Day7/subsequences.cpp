#include <bits/stdc++.h>
using namespace std;

class Solution {
public:


    void solve(vector<string>&ans, string str, string output, int i){

        //base case
        if(i>=str.length()){
            if(output.length() > 0){
                ans.push_back(output);
            }
            return;
        }

        // Exclude current character
        solve(ans,str,output, i+1);

        // Include current character
        output.push_back(str[i]);
        solve(ans,str,output, i+1);
    }

    vector<string> subsequences(string str){
        vector<string>ans;
        string output = "";

        solve(ans,str,output,0);
        return ans;
    }
};

int main() {
    Solution obj;

    string str;
    cin >> str;

    vector<string> ans = obj.subsequences(str);

    for (string s : ans) {
        cout << s << endl;
    }

    return 0;
}