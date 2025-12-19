#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mxN = 1e5+5;

ll grid[4][mxN];
ll dp[16][mxN];

int main() {

    ll n;
    cin >> n;

    for (int i = 0; i < 4; ++i) {
        for (ll j = 0; j < n;++j) {
            cin >> grid[i][j];
        }
    }

    for (ll i = 1; i <= n; ++i) {
        for (ll mask = 0; mask < (1<<4); ++mask) {
            if ((mask & (mask << 1)) > 0) continue;
            ll smask = 0;
            for (ll j = 0; j < 4; ++j) {
                if ((mask >> j) & 1)smask += max(0LL, grid[j][i-1]);
            }
            for (ll pmask = 0; pmask < (1<<4); ++pmask) {
                if ((pmask & (pmask << 1)) > 0) continue;
                if ((mask & pmask)>0) continue;
                dp[mask][i] = max(dp[mask][i], smask + dp[pmask][i-1]);
            }
        }
    }
    ll ans = 0;

    for (ll i = 0; i < 16; ++i) ans = max(ans, dp[i][n]);

    cout << ans << endl;
}
