#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;

const int mxN = 3005;

int n, m, k;
vector<pair<int, ld>> adj[mxN];
vector<pair<int, int>> users;
ld dist[mxN];

int main() {
    cin >> k >> n;
    for (int i = 0; i < k; ++i) {
        int u, f;
        cin >> u >> f;
        users.emplace_back(u, f);
    }
    cin >> m;

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;

        ld x = 1.0 / (ld)w;
        adj[u].emplace_back(v, x);
        adj[v].emplace_back(u, x);
    }
    for (int i = 1; i <= n; ++i) {
        dist[i] = numeric_limits<ld>::infinity();
    }

    using State = pair<ld, int>;
    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({0.0, 0});

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

    ld ans = 0.0;
    for (auto [u, f] : users) {
        ans += dist[u] * (ld)f;
    }
    ll ansl = ceil(ans);
    cout << ansl << endl;
}
