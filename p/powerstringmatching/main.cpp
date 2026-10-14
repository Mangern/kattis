#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string ss, ts;
    cin >> ss >> ts;

    string_view s = ss;
    string_view t = ts;

    vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
    dp[0][0] = 1;
    for (int j = 1; j <= n; ++j)dp[0][j] = 1;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = dp[i][j-1];

            for (int l = 1; l <= j && !dp[i][j]; ++l) {
                string_view suf = s.substr(j-l, l);
                for (int k = 1; i - k * l >= 0; ++k) {
                    if (t.substr(i - k * l, l) != suf) {
                        break;
                    }
                    if (dp[i - k * l][j-l]) {
                        dp[i][j] = 1;
                        break;
                    }
                }
            }
        }
    }
    cout << (dp[m][n] ? "yes" : "no") << endl;
}
