#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[105][205][205];

int main() {
    ll q, n, d;
    cin >> q >> n >> d;

    string f1,f2;
    cin >> f1 >> f2;

    dp[0][0][0] = 1;

    for (ll i = 1; i <= n; ++i) {
        for (ll d1 = 0; d1 <= d; ++d1) {
            for (ll d2 = 0; d2 <= d; ++d2) {
                if (f1[i-1] == f2[i-1]) {
                    dp[i][d1][d2] = dp[i-1][d1][d2];
                    if (d1 > 0 && d2 > 0) {
                        dp[i][d1][d2] += (q - 1) * dp[i-1][d1-1][d2-1];
                    }
                } else {
                    if (d2 > 0)dp[i][d1][d2] += dp[i-1][d1][d2-1];
                    if (d1 > 0)dp[i][d1][d2] += dp[i-1][d1-1][d2];
                    if (d1 > 0 && d2 > 0)
                        dp[i][d1][d2] += (q - 2) * dp[i-1][d1-1][d2-1];
                }
            }
        }
    }

    ll ans = 0;
    for (ll d1 = 0; d1 <= d; ++d1) {
        ans += dp[n][d1][d-d1];
    }
    cout << ans << endl;
}
