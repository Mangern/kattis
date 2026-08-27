#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1000000;

ll dp[(ll)1e4+5];

int main() {
    ll n;
    cin >> n;

    dp[0] = 1;
    dp[1] = 1;

    for (ll i = 2; i <= n; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
        if (dp[i] >= mod)dp[i] -= mod;
    }
    cout << dp[n] << endl;
}
