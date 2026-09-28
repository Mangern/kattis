#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9+7;

const int mxN = 1e4+5;

ll n, m;
ll dp[mxN];

ll hit[mxN];
vector<ll> adj[mxN];
unordered_map<string, ll> id;

// defeat 1 bloon `u`
ll defeat(ll u) {
    ll &r = dp[u];
    if (r != -1) return r;

    r = hit[u] % MOD;

    for (ll v : adj[u]) {
        r += defeat(v);
        r %= MOD;
    }
    return r;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        dp[i] = -1;
        string s;
        cin >> s;
        id[s] = i;
        cin >> hit[i];
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            string t;
            cin >> t;
            adj[i].push_back(id[t]);
        }
    }

    ll ans = 0;
    for (int i = 0; i < m; ++i) {
        string s;
        ll c;
        cin >> s >> c;

        ans += (c * defeat(id[s])) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}
