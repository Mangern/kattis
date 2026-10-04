#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

const int mxN = 2005;

const int INF = 1e9;

int n, m, k, maxW;

vector<ii> adj[mxN];

int main() {
    cin >> n >> m >> k;
    vector<int> wgts;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        wgts.push_back(w);
    }
    sort(begin(wgts), end(wgts));
    wgts.erase(unique(begin(wgts), end(wgts)), end(wgts));

    {
        queue<int> q;
        vector<int> dist(n,-1);
        dist[0] = 0;
        q.push(0);

        while (q.size()) {
            int u = q.front();
            q.pop();
            for (auto [v, _] : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        if (dist[n-1] <= k) {
            cout << 0 << endl;
            return 0;
        }
    }

    int ans = INF;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    vector<int> dist(n, 0);
    for (int w_bound : wgts) {
        for (int i = 1; i < n; ++i) {
            dist[i] = INF;
        }
        pq.push({0, 0});
        dist[0] = 0;
        while (pq.size()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (dist[u] < d) continue;

            for (auto [v, w] : adj[u]) {
                w = (w < w_bound ? w_bound : w);

                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        ans = min(ans, dist[n-1] - k * w_bound);
    }
    cout << ans << endl;
}
