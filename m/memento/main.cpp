#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

vector<pii> run(vector<pii> edges) {
    int n = 1000;

    vector<int> deg(n, 0);
    vector<vector<int>> adj(n);
    for (auto [u, v] : edges) {
        ++deg[u];
        ++deg[v];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int u = max_element(begin(deg), end(deg)) - begin(deg);

    if (deg[u] >= 30) {
        return {};
    }
    vector<pii> add;

    for (int v = 0; v < n && add.size() < 30; ++v) {
        if (v == u) continue;
        auto e = end(adj[u]);
        if (find(begin(adj[u]), e, v) != e) {
            continue;
        }
        add.push_back({u,v});
    }
    return add;
}
