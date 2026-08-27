#include <bits/stdc++.h>
#include <limits>
#include <queue>
using namespace std;
using ll = long long;
using ii = array<ll, 2>;

const ll inf = numeric_limits<ll>::max() / 8;

const int mxN = 105;
ll n,m;
ll dist[mxN];
ll a[mxN];
ll dp[mxN];
vector<ii> adj[mxN];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        dist[i] = inf;
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w, --u, --v;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    dist[0] = 0;
    dp[0] = a[0];

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({dist[0], 0});

    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (dist[u] < d) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dp[v] = dp[u] + a[v];
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            } else if (dist[u] + w == dist[v] && dp[u] + a[v] > dp[v]) {
                dp[v] = dp[u] + a[v];
            }
        }
    }

    if (dist[n-1] == inf) {
        cout << "impossible" << endl;
        return 0;
    }

    cout << dist[n-1] << " " << dp[n-1] << endl;
}
