#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <limits>
using namespace std;

const int K = 23;

int dp[1<<K];

int solve(int mask) {
    if (dp[mask] != -1) return dp[mask];

    dp[mask] = __builtin_popcount(mask);

    for (int j = 1; j < K; ++j) {
        int cur = (mask>>j)&1;
        int prev = (mask>>(j-1))&1;
        
        if (!cur || !prev) continue;

        if (j > 1 && !((mask>>(j-2))&1)) {
            dp[mask] = min(dp[mask], solve(mask^(1<<j)^(1<<(j-1))^(1<<(j-2))));
        }
        if (j < K - 1 && !((mask>>(j+1))&1)) {
            dp[mask] = min(dp[mask], solve(mask^(1<<j)^(1<<(j-1))^(1<<(j+1))));
        }
    }
    return dp[mask];
}

void testCase() {
    string s;
    cin >> s;

    int n = s.length();

    int mask = 0;
    for (char c : s) {
        mask <<= 1;
        if (c == 'o')mask |= 1;
    }
    cout << solve(mask) << endl;
}

void pre() {
    memset(dp, -1, sizeof dp);
}

int main() {
    pre();
    int t;
    cin >> t;
    while (t-->0)testCase();
}
