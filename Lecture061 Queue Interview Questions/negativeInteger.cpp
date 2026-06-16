#include<iostream>
#include<deque>
#include<vector>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    deque<long long int> dq;
    vector<long long> ans;

    // Process first window of size K
    for(int i = 0; i < K; i++) {
        if(A[i] < 0) {
            dq.push_back(i);
        }
    }

    // Add result of first window
    if(!dq.empty()) {
        ans.push_back(A[dq.front()]);
    } else {
        ans.push_back(0);
    }

    // Process the remaining windows
    for(int i = K; i < N; i++) {
        // Remove elements out of this window
        if(!dq.empty() && dq.front() <= i - K) {
            dq.pop_front();
        }

        // Add current element if it is negative
        if(A[i] < 0) {
            dq.push_back(i);
        }

        // Append first negative integer of current window
        if(!dq.empty()) {
            ans.push_back(A[dq.front()]);
        } else {
            ans.push_back(0);
        }
    }

    return ans;
}

int main() {
    long long int A[] = {12, -1, -7, 8, -15, 30, 16, 28};
    long long int N = sizeof(A) / sizeof(A[0]);
    long long int K = 3;

    vector<long long> result = printFirstNegativeInteger(A, N, K);
    
    for(auto val : result) {
        cout << val << " ";
    }

    return 0;
}
