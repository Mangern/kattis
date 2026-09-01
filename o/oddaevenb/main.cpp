#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9+7;

int main() {
    ll n;
    cin >> n;

    vector<pair<ll, ll>> dp(n+1, {0,0});
    dp[0] = {1, 1};

    for (ll i = 1; i <= n; ++i) {
        // assume starting with a:
        for (ll l = 1; l <= i; l += 2) {
            // next sequence must start with B
            dp[i].first += dp[i-l].second;
            dp[i].first %= MOD;
        }
        // assume starting with b:
        for (ll l = 2; l <= i; l += 2) {
            dp[i].second += dp[i-l].first;
            dp[i].second %= MOD;
        }
    }

    ll ans = (dp[n].first + dp[n].second) % MOD;
    cout << ans << endl;
}
