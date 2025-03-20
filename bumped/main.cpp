#include <bits/stdc++.h>
#include <limits>
#include <queue>
using namespace std;
using ll = long long;
using ii = array<ll, 2>;

const int mxN = 50005;

int n, m, f, s, t;
vector<ii> adj[2 * mxN];
ll dist[2 * mxN];

int main() {
    cin >> n >> m >> f >> s >> t;

    for (int i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        adj[u+n].push_back({v+n, w});
        adj[v+n].push_back({u+n, w});
    }

    for (int i = 0; i < f; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v+n, 0});
    }

    for (int i = 0; i < 2 * n; ++i) {
        dist[i] = numeric_limits<ll>::max();
    }

    dist[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, s});

    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (dist[u] < d) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    cout << min(dist[t], dist[t+n]) << endl;

}
