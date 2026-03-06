#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;

    vector<ll> a(n);
    for (auto & x : a) cin >> x;

    vector<ll> dp(n+2);
    dp[n+1] = 0;
    dp[n] = 0;
    dp[n-1] = 0;

    for (ll i = n - 2; i >= 0; --i) {
        dp[i] = dp[i+1];
        for (ll j = i + 1; j < n; ++j) {
            ll profit = a[j] - a[i];
            dp[i] = max(dp[i], profit + dp[j+2]);
        }
    }
    cout << dp[0] << endl;
}
