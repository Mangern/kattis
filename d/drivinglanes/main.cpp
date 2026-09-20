#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = numeric_limits<ll>::max() / 8;

const int mxN = 256;

ll n, m, k, r;
ll dp[mxN][mxN];

ll lane_l[mxN];

ll curve_s[mxN];
ll curve_c[mxN];

int main() {
    for (int i = 0; i < mxN; ++i) {
        for (int j = 0; j < mxN; ++j) {
            dp[i][j] = INF;
        }
    }

    cin >> n >> m;
    cin >> k >> r;

    for (int i = 0; i < n; ++i) {
        cin >> lane_l[i+1];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> curve_s[i+1] >> curve_c[i+1];
    }

    dp[0][1] = 0;

    for (ll i = 1; i <= n; ++i) {
        for (ll lane_end = 1; lane_end <= m; ++lane_end) {
            for (ll lane_start = 1; lane_start <= m; ++lane_start) {
                ll n_switch = abs(lane_end - lane_start);
                if (k * n_switch > lane_l[i]) {
                    continue;
                }
                ll switch_cost = (k + r) * n_switch;
                ll travel_cost = lane_l[i] - k * n_switch;

                ll curve_cost = 0;

                if (i > 1) {
                    curve_cost = curve_s[i-1] + curve_c[i-1] * lane_start;
                }

                ll tot_cost = dp[i-1][lane_start] + switch_cost + travel_cost + curve_cost;
                dp[i][lane_end] = min(dp[i][lane_end], tot_cost);
            }
        }
    }

    cout << dp[n][1] << endl;
}
