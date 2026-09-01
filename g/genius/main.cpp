#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, t, p, q, x0;
    cin >> k >> t >> p >> q >> x0;

    vector<int> x(t);
    x[0] = x0;
    for (int i = 1; i < t; ++i) {
        x[i] = x[i-1] * p % q;
    }
    for (int i = 0; i < t; ++i) x[i] %= 4;

    vector<double> dp(t+1, 0.0);
    dp[0] = 1.0;

    for (int i = 0; i < t; ++i) {
        double w0, w1, w2, w3;
        cin >> w0 >> w1 >> w2 >> w3;

        double win0 = w0 / (w0 + w1);
        double win1 = w1 / (w0 + w1);
        double win2 = w2 / (w2 + w3);
        double win3 = w3 / (w2 + w3);

        array<double, 4> p;
        p[0] = win0 * (win2 * w0 / (w0 + w2) + win3 * w0 / (w0 + w3));
        p[1] = win1 * (win2 * w1 / (w1 + w2) + win3 * w1 / (w1 + w3));
        p[2] = win2 * (win0 * w2 / (w0 + w2) + win1 * w2 / (w1 + w2));
        p[3] = win3 * (win0 * w3 / (w0 + w3) + win1 * w3 / (w1 + w3));

        vector<double> ndp(t+1, 0.0);

        for (int j = 0; j <= t; ++j) {
            ndp[j] = dp[j] * (1.0 - p[x[i]]);
            if (j > 0) {
                ndp[j] += dp[j-1] * p[x[i]];
            }
        }
        swap(dp, ndp);
    }

    double ans = 0.0;
    for (int i = k; i <= t; ++i) {
        ans += dp[i];
    }
    cout << setprecision(8) << fixed << ans << endl;
}
