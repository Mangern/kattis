#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 1005;

vector<pair<ll, ll>> adj[mxN];
ll leaf[mxN];

pair<ll, ll> dfs(int u, int cf = -1) {
    ll ret = 0;
    ll cnt = leaf[u];

    for (auto [v, w] : adj[u]) if (v != cf) {
        auto [swgt, scnt] = dfs(v, u);
        if (scnt > 0) {
            ret += swgt;
            ret += 2 * w;
        }
        cnt += scnt;
    }

    return {ret, cnt};
}

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n - 1; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for (int i = 0; i < k; ++i) {
        int u;
        cin >> u;
        leaf[u] = 1;
    }

    cout << dfs(0).first << endl;
}
