#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 1e6+5;
ll s, p, m, n;

ll t[mxN];

// cheapest to complete [i, i+1, ..., n - 1]
ll dp[mxN];


int main() {
    cin >> s >> p >> m >> n;

    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    for (int i = n - 1; i >= 0; --i) {
        // single ticket
        dp[i] = dp[i + 1] + s;

        int j = lower_bound(t, t + n, t[i] + m) - t;

        dp[i] = min(dp[i], p + dp[j]);
    }

    cout << dp[0] << endl;
}
