#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll = long long;
using ii = array<ll, 2>;

const int mxN = 1e4+7;
const ll INF = 1e9;

int n, m;
vector<ii> adj[mxN];
vector<int> p[mxN];
ll dist[mxN];
bool vis[mxN];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        dist[i] = INF;
    }

    for (int i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    dist[0] = 0;
    pq.push({dist[0], 0});

    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (dist[u] < d) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                p[v].clear();
                p[v].push_back(u);
                pq.push({dist[v], v});
            } else if (dist[u] + w == dist[v]) {
                p[v].push_back(u);
            }
        }
    }

    vis[n-1] = 1;
    ll ans = 0;

    queue<int> q;
    q.push(n-1);

    while (q.size()) {
        int u = q.front();
        q.pop();

        for (int v : p[u]) {
            ans += dist[u] - dist[v];
            if (!vis[v]) {
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    ans <<= 1LL;
    cout << ans << endl;

    return 0;
}
