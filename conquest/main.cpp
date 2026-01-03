#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll, 2>;

const int mxN = 2e5+5;

int n, m;
vector<int> adj[mxN];
bool vis[mxN];
ll val[mxN];

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v, --u, --v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; ++i) {
        cin >> val[i];
    }

    ll cur = val[0];
    vis[0] = 1;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int u : adj[0]) if (!vis[u]) {
        vis[u] = 1;
        pq.push({val[u], u});
    }

    while (pq.size()) {
        auto [vl, u] = pq.top();
        pq.pop();
        if (vl >= cur) break;
        cur += vl;

        for (int v : adj[u]) if (!vis[v]) {
            vis[v] = 1;
            pq.push({val[v], v});
        }
    }

    cout << cur << endl;
}
