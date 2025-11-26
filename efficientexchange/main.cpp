#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;

    ll n = s.length();

    vector<ll> a(n, 0);
    vector<ll> b(n, 0);

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        a[i] = s[i] - '0';
        b[i] = 10 - a[i];
    }

    vector<ll> dp(n);

    for (int i = n - 1; i >= 0; --i) {
        dp[i] = a[i];
        if (i < n - 1)dp[i] += dp[i+1];

        ll rem = 10;
        ll tot = 0;
        for (int j = i; j < n; ++j) {
            tot += b[j];
            dp[i] = min(dp[i], tot + (j<n-1?dp[j+1]:0) + 1);
            --tot;
        }
    }

    cout << dp[0] << endl;
}
