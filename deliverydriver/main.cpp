#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll trv[3][3];

    cin >> trv[0][1];
    cin >> trv[0][2];
    cin >> trv[1][2];
    trv[0][0] = 0;
    trv[1][1] = 0;
    trv[2][2] = 0;
    trv[1][0] = trv[0][1];
    trv[2][0] = trv[0][2];
    trv[2][1] = trv[1][2];

    ll n;
    cin >> n;

    vector<vector<ll>> dp(3, vector<ll>(n+1, 0));

    dp[0][0] = dp[1][0] = dp[2][0] = 0;

    vector<vector<ll>> a(3, vector<ll>(n));
    for (int i = 0; i < 3; ++i) {
        for (auto &x : a[i]) cin >> x;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                dp[j][i+1] = max(dp[j][i+1], -trv[k][j] + a[k][i] + dp[k][i]);
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < 3; ++i)ans=max(ans,dp[i][n]);
    cout << ans << endl;
}
