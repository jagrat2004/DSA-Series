#include <bits/stdc++.h>
using namespace std;

int solve(int n, int x, int y, int z) {
    if (n == 0)
        return 0;
    if (n < 0)
        return INT_MIN;

    int a = solve(n - x, x, y, z);
    int b = solve(n - y, x, y, z);
    int c = solve(n - z, x, y, z);

    // fixed: guard against INT_MIN overflow when adding 1
    if (a != INT_MIN) a += 1;
    if (b != INT_MIN) b += 1;
    if (c != INT_MIN) c += 1;

    return max(a, max(b, c));
}

int cutSegments(int n, int x, int y, int z) {
    int ans = solve(n, x, y, z);
    if (ans < 0)       // if no valid cut possible, return 0
        return 0;
    else
        return ans;
}

int main() {
    int n, x, y, z;
    cout << "Enter total length (n): ";
    cin >> n;
    cout << "Enter segment lengths (x y z): ";
    cin >> x >> y >> z;

    cout << "Maximum number of segments: " << cutSegments(n, x, y, z) << endl;

    return 0;
}