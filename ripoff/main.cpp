#include <bits/stdc++.h>
#include <limits>
using namespace std;
using ll = long long;

const int mxN = 205;

ll a[mxN];
ll dp[mxN][mxN]; // 
ll n,s , t;

int main() {
    for (;;) {
        cin >> n;
        if (!n) break;
        cin >> s >> t;

        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int tleft = 0; tleft <= t; ++tleft) {
            dp[n+1][tleft] = 0;
        }

        for (int i = n; i >= 0; --i) {
            dp[i][0] = -numeric_limits<ll>::max() / 8;
            for (int tleft = 1; tleft <= t; ++tleft) {
                dp[i][tleft] = -numeric_limits<ll>::max() / 8;
                for (int j = 1; j <= s; ++j) {
                    dp[i][tleft] = max(dp[i][tleft], a[i] + dp[min(n+1, (ll)i+j)][tleft-1]);
                }
            }
        }

        cout << dp[0][t] << endl;
    }
}
