#include <bits/stdc++.h>
#include <queue>
using namespace std;
using edge = pair<double,int>;

const double inf = numeric_limits<double>::infinity();

int main() {
    for (;;) {
        int n, m;
        cin >> n >> m;
        if (!n) break;

        vector<vector<edge>> adj(n);

        for (int i = 0; i < m; ++i) {
            int u, v; double f;
            cin >> u >> v >> f;

            if (f != 0) {
                adj[u].push_back({-log(f), v});
                adj[v].push_back({-log(f), u});
            }
        }
        vector<double> dist(n, inf);

        dist[0] = 0.0;

        priority_queue<edge,vector<edge>,greater<edge>> pq;
        pq.push({0.0, 0});

        while (pq.size()) {
            auto [d, u] = pq.top();
            pq.pop();

            for (auto [w, v] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        printf("%.4f\n", pow(M_E, -dist[n-1]));
    }
}
