#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >>n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;

    if (n < 3) {
        cout << n << endl;
        return 0;
    }

    // dp[i][j], i < j: Longest subsequence ending with i, ..., j
    vector<vector<ll>> dp(n, vector<ll>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            dp[i][j] = 2;

            // find k such that a[k] + a[i] == a[j]
            // -> a[k] = a[j] - a[i]
            for (int k = 0; k < i; ++k) {
                if (a[k] + a[i] == a[j]) {
                    dp[i][j] = max(dp[i][j], dp[k][i] + 1);
                }
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
}
