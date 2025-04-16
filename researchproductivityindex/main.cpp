#include <bits/stdc++.h>
using namespace std;

const int mxN = 105;

int n;
double p[mxN];

// dp[i][k]: prob that exactly k of the papers from i..n gets accepted
double dp[mxN][mxN];

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i] /= 100.0;
    }

    sort(p, p+n);
    reverse(p,p+n);

    double ans = 0.0;
    for (int k = 1; k <= n; ++k) {
        dp[k][0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[k][i] = pow((double)i, (double)i/(double)k);
        }
        for (int i = k - 1; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                dp[i][j] = p[i] * dp[i+1][j+1] + (1 - p[i]) * dp[i+1][j];
            }
        }
        ans = max(ans, dp[0][0]);

    }


    cout << setprecision(7) << fixed << ans << endl;
}
