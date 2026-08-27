#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = numeric_limits<ll>::max() / 8;

int main() {
    ll n, k;
    cin >> n >> k;

    vector<ll> mat(n*n);
    for (auto & x : mat)cin >> x;

    vector<ll> dp(n*n,-1);

    function<ll(ll)> solve = [&](ll u) {
        if (dp[u] != -1) return dp[u];
        if (mat[u] == k) {
            return dp[u] = 0;
        }

        ll &r = dp[u];
        r = INF;
        ll i1 = u / n;
        ll j1 = u % n;
        for (int v = 0; v < n * n; ++v) if (mat[v] == mat[u] + 1) {
            ll i2 = v / n;
            ll j2 = v % n;

            r = min(r, abs(i1 - i2) + abs(j1 - j2) + solve(v));
        }
        return r;
    };

    ll ans = INF;
    for (int i = 0; i < n * n; ++i) if (mat[i] == 1) {
        ans = min(ans,solve(i));
    }

    if (ans==INF)ans=-1;
    cout << ans << endl;
}
