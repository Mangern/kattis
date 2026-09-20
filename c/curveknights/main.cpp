#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 51;

int n, m;
ll need[mxN];
bool vis[mxN];
vector<pair<int, ll>> adj[mxN];

void dfs(int u) {
    vis[u] = 1;
    for (auto [v, w] : adj[u]) {
        if (!vis[v]) dfs(v);
        need[u] += w * need[v];
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> need[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }

    for (int i = 0; i < n; ++i) {
        if (!vis[i]) dfs(i);
    }

    for (int i = 0; i < n; ++i) cout << need[i] << ' ';
    cout << endl;
}
