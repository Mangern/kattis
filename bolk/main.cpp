#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 1e3+5;

ll dp[mxN][mxN];

int n, m;
ll cost[mxN];
ll val[mxN];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> cost[i] >> val[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= m; ++j) {
            dp[i][j] = (i>0 ? dp[i-1][j] : 0);

            if (j >= cost[i]) {
                dp[i][j] = max(dp[i][j], val[i] + (i>0?dp[i-1][j-cost[i]]:0LL));
            }
        }
    }
    cout << dp[n-1][m] << endl;
}
