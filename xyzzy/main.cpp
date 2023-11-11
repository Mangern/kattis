#include <bits/stdc++.h>
#include <limits>
#include <queue>
using namespace std;
using vi = vector<int>;
using ll = long long;

const ll INF = numeric_limits<ll>::max();

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

    edge.push_back({0, 1, -100});

    for (int u = 1; u < n; ++u) {
        for (auto v : adj[u]) {
            edge.push_back({u, v, -val[v]});
            //cout << u << " -> " << v << ": " << -val[v] << endl;
        }
    }

    vector<ll> dist(n, INF);
    dist[0] = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (auto [u, v, w] : edge) {
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    if (dist[n-1] == INF) {
        cout << "hopeless" << endl;
        return;
    }

    vector<bool> good(n, 0);

    for (auto [u, v, w] : edge) {
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            good[u] = 1;
        }
    }


    good[n-1] = 1;
    queue<int> q;
    q.push(0);
    vector<bool> vis(n, 0);
    vis[0] = 1;
    while (q.size()) {
        int u = q.front();
        if (good[u]) {
            cout << "winnable" << endl;
            return;
        }
        q.pop();
        for (auto v : adj[u]) if (dist[v] < 0 && !vis[v]) {
            vis[v] = 1;
            q.push(v);
        }
    }

    cout << "hopeless" << endl;
}

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == -1)break;

        solve(n);
    }
}
