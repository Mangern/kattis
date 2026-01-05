#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll t;
    cin >> t;
    while (t-->0) {
        ll tc, m, n;
        cin >> tc >> m >> n;

        vector<ll> pw = {1};
        ll mul = 1;
        while (true) {
            pw.push_back(pw.back() * m);
            if (pw.back()>n)break;
        }

        ll k = pw.size()+1;

        vector<vector<ll>> dp(n+1, vector<ll>(k, 0));

        for (int i = 0; i < k; ++i)dp[0][i] = 1;
        for (ll i = 1; i <= n; ++i) {
            for (ll j = 0; j < k; ++j) {
                // using pw [..j]
                for (ll p = 0; p <= j; ++p) {
                    if (pw[p] <= i) {
                        dp[i][j] += dp[i-pw[p]][p];
                    } else break;
                }
            }
        }
        cout << tc << " " << dp[n][k-1] << endl;
    }
}
