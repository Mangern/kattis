#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll mxN = 1e5+5;
const ll K = 200;
const ll MOD = 1e9+7;

ll n;
ll dp[mxN];
ll xs[mxN];
ll ds[mxN];

ll table[K][mxN];
ll tindex[K][mxN];

ll table_range_sum(ll d, ll from, ll to) {
    ll fi = tindex[d][from];
    ll ti = tindex[d][to];
    ll sub = 0;

    if (to + d <= n) {
        sub = table[d][ti + 1];
    }

    return ((table[d][fi] - sub)%MOD+MOD)%MOD;
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> ds[i] >> xs[i];
    }

    for (ll d = 1; d < K; ++d) {
        ll ptr = 0;
        for (ll r = 0; r < d; ++r) {
            for (ll i = (r ? r : d); i <= n; i += d) {
                tindex[d][i] = ptr++;
            }
        }
    }

    for (ll i = n; i >= 1; --i) {
        dp[i] = 1;

        if (ds[i] == 0) { }
        else if (ds[i] >= K) {
            for (ll t = 1; t <= xs[i]; ++t) {
                if (i + t * ds[i] > n) break;
                dp[i] += dp[i + t * ds[i]];
                dp[i] %= MOD;
            }
        } else if (i + ds[i] <= n) {
            // Find the correct range sum in table
            // i + t * ds[i] <= n
            // t * ds[i] <= n - i
            // t <= (n - i) / ds[i]
            ll t = min(xs[i], (n - i) / ds[i]);
            ll rs = table_range_sum(ds[i], i+ds[i], i + t * ds[i]);
            dp[i] += rs;
            dp[i] %= MOD;
        }

        for (ll d = 1; d < K; ++d) {
            ll next = i + d;
            if (next <= n) {
                table[d][tindex[d][i]] = table[d][tindex[d][next]];
            } else {
                table[d][tindex[d][i]] = 0;
            }
            table[d][tindex[d][i]] += dp[i];
            table[d][tindex[d][i]] %= MOD;
        }
    }

    cout << dp[1] << endl;
}
