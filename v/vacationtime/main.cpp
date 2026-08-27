#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll,2>;

const int mxN = 20005;
const ll INF = numeric_limits<ll>::max() / 4;

ll n, m;

vector<ii> adj[mxN];
ll dist[mxN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        ll u, v, w;
        string s;
        cin >> u >> v >> w >> s;

        adj[u+n].push_back({v+n,w});
        if (s == "A380") {
            adj[u].push_back({v+n,w});
        } else {
            adj[u].push_back({v,w});
        }
    }

    for (int i = 1; i < 2 * n; ++i) {
        dist[i] = INF;
    }

    priority_queue<ii, vector<ii>, greater<ii>> pq;

    pq.push({0,0});

    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (dist[u] < d) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v],v});
            }
        }
    }

    if (dist[n+n-1] == INF) {
        cout << -1 << endl;
    } else {
        cout << dist[n+n-1] << endl;
    }
}
