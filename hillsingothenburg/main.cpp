#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll = long long;
using ii = array<ll,2>;

const int mxN = 1e5+5;
const ll INF = numeric_limits<ll>::max() / 5;

int n, m;
vector<ii> adj[mxN];
ll dist[mxN];
ll a[mxN];

int main() {
    cin >> n >> m;

    int s, t;
    cin >> s >> t, --s, --t;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        dist[i] = INF;
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v, --u, --v;

        adj[u].push_back({v, max(0LL, a[v] - a[u])});
        adj[v].push_back({u, max(0LL, a[u] - a[v])});
    }

    dist[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({dist[s], s});

    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (dist[u] < d) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << dist[t] << endl;
}
