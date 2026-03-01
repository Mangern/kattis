#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = numeric_limits<ll>::max() / 4;

int main() {
    ll n;
    cin >> n;

    string s;
    cin >> s;

    // Time to complete starting at pos i, in state j
    vector<vector<ll>> dp(n+1, vector<ll>(3, INF));

    dp[n-1][0] = 0;
    dp[n-1][1] = 0;
    dp[n-1][2] = 0;

    for (int i = n - 2; i >= 0; --i) {
        switch (s[i]) {
            case '.':
                dp[i][0] = dp[i+1][0] + 1;
                dp[i][1] = dp[i+1][1] + 2;
                dp[i][2] = dp[i+1][2] + 2;
                break;
            case 'S':
                dp[i][0] = INF;
                dp[i][1] = 1 + dp[i+1][0]; // Turn into little mario
                dp[i][2] = 2 + dp[i+1][1]; // Turn into super mario
                break;
            case '?':
                dp[i][0] = min(dp[i+1][0] + 1, dp[i+1][1] + 2);
                dp[i][1] = min(dp[i+1][1] + 2, dp[i+1][2] + 2);
                dp[i][2] = dp[i+1][2] + 2;
                break;
        }
    }

    ll ans = *min_element(begin(dp[0]), end(dp[0]));
    if (ans >= INF) cout << -1 << endl;
    else cout << ans << endl;
}
