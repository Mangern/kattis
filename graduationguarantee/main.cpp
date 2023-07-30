#include <bits/stdc++.h>
using namespace std;

const int mxN = 5e3+4;

int n, k;
double p[mxN];
double dp[mxN][mxN];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i)cin >>p[i];
    sort(p,p+n);
    reverse(p,p+n);

    dp[0][0] = 1.0;
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = dp[i-1][0] * (1 - p[i-1]);
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = p[i-1] * dp[i-1][j-1] + (1 - p[i-1]) * dp[i-1][j];
        }
    }

    double ans = 0.0;
    for (int m = 1; m <= n; ++m) {
        // answer first m questions
        double sm = 0.0;
        for (int a = (m+k+1)/2; a <= m; ++a) {
            sm += dp[m][a];
        }

        ans = max(ans, sm);
    }
    cout << ans << endl;
}
