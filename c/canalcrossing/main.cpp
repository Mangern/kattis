#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 1e5+5;

int n, m;
vector<array<ll, 2>> adj[mxN];
int nbridge[mxN];
ll ans;

int dfs(int u = 0, int cf = -1) {
    int cnt = nbridge[u];
    for (auto [v, w] : adj[u]) if (v != cf) {
        if (dfs(v, u)) {
            ans += w;
            ++cnt;
        }
    }

    return cnt & 1;
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w, --u, --v;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v, --u, --v;
        ++nbridge[u];
        ++nbridge[v];
    }

    dfs();
    cout << ans << endl;
}
