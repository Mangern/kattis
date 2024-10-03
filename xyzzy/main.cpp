#include <bits/stdc++.h>
#include <limits>
#include <queue>
using namespace std;
using vi = vector<int>;
using ll = long long;

const ll INF = 2e9;

void solve(int n) {
    ++n;
    vector<vi> adj(n, vi());
    vi val(n, 0);

    vector<array<ll,3>> edge;

    int m = 1;
    for (int u = 1; u < n; ++u) {
        cin >> val[u];
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int v;
            cin >> v;
            adj[u].push_back(v);
            ++m;
        }
    }
    adj[0].push_back(1);

    edge.push_back({0, 1, -100-val[1]});

    for (int u = 1; u < n; ++u) {
        for (auto v : adj[u]) {
            edge.push_back({u, v, -val[v]});
            //cout << u << " -> " << v << ": " << -val[v] << endl;
        }
    }

    vector<ll> dist(n, INF);
    vector<bool> good(n, 0);
    dist[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (auto [u, v, w] : edge) {
            if (dist[u] < INF && dist[u] + w < 0) {
                dist[v] = min(dist[v], dist[u] + w);
            }
        }
    }

    bool flag = 1;
    
    while (flag) {
        flag = 0;
        for (auto [u, v, w] : edge) if (dist[u] != INF) {
            if (dist[u] + w < dist[v] && !good[v] && dist[u] + w < 0) {
                dist[v] = -INF;
                flag = 1;
                good[v] = 1;
            }
        }
    }
    cout << ((dist[n-1] < 0 || good[n-1]) ? "winnable" : "hopeless") << endl;
}

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == -1)break;

        solve(n);
    }
}
