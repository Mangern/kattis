#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v,w);
    }
    vector<int> dist(n, 100 * 2 * n);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    int s, t;
    cin >> s >> t;
    dist[s] = 0;
    pq.push({0,s});
    vector<vector<int>> radj(n);
    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (dist[u] < d) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                radj[v].clear();
                pq.push({dist[u] + w, v});
            }
            if (dist[u] + w <= dist[v]) {
                radj[v].push_back(u);
                dist[v] = dist[u] + w;
            }
        }
    }
    vector<int> in(n,0);
    for (int u = 0; u < n; ++u) {
        for (auto v : radj[u]) {
            ++in[v];
        }
    }
    queue<int> q;
    vector<int> cnt(n, 0);
    cnt[t] = 1;
    for (int u = 0; u < n; ++u) {
        if (in[u] == 0) {
            q.push(u);
        }
    }
    while (q.size()) {
        int u = q.front();
        q.pop();

        for (int v : radj[u]) {
            cnt[v] += cnt[u];
            if (!--in[v]) {
                q.push(v);
            }
        }
    }

    cout << cnt[s] << endl;
}
