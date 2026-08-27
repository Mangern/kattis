#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    ll n = s.length();

    vector<vector<ll>> dp(2, vector<ll>(n+1));

    dp[0][n] = 0;
    dp[1][n] = 1;

    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == 'N') {
            dp[0][i] = min(1 + dp[0][i+1], 1 + dp[1][i+1]);
            dp[1][i] = min(2 + dp[0][i+1], 0 + dp[1][i+1]);
        } else if (s[i] == 'S') {
            dp[0][i] = min(0 + dp[0][i+1], 2 + dp[1][i+1]);
            dp[1][i] = min(1 + dp[0][i+1], 1 + dp[1][i+1]);
        } else {
            dp[0][i] = min(1 + dp[0][i+1], 2 + dp[1][i+1]);
            dp[1][i] = min(2 + dp[0][i+1], 1 + dp[1][i+1]);
        }
    }

    cout << dp[0][0] << endl;
}
