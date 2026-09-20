#include <bits/stdc++.h>
using namespace std;

const int mxN = 1005;

int n, m;
double p;
double dp[mxN][mxN];

int main() {
    cin >> n >> m >> p;

    dp[n-1][m-1] = 0;

    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            if (i == n - 1 && j == m - 1) continue;

            if (i == n - 1) {
                dp[i][j] = p / 4.0 + dp[i][j+1];
            } else if (j == m - 1) {
                dp[i][j] = p / 4.0 + dp[i+1][j];
            } else {
                double good = min(dp[i+1][j], dp[i][j+1]);
                double bad = max(dp[i+1][j], dp[i][j+1]);
                // 50% chance to get good directly
                dp[i][j] = 0.5 * good;

                // if we get bad we should wait if wait time is <= bad - good
                double p_wait = min(1.0, (bad - good) / p);
                double e_p = min(bad - good, p) / 2.0;
                dp[i][j] += 0.5 * p_wait * (e_p + good);
                dp[i][j] += 0.5 * (1.0 - p_wait) * bad;
            }
        }
    }

    cout << setprecision(9) << fixed << dp[0][0] << endl;
}
