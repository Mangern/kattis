#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll, 2>;
using tup = array<ll, 3>;

const ll INF = numeric_limits<ll>::max() / 8;

int main() {
    int m;
    cin >> m;

    unordered_map<string, int> id;
    int n = 0;
    string s;
    cin >> s;
    id[s] = n++;
    cin >> s;
    id[s] = n++;

    vector<tup> edge;
    for (int i = 0; i < m; ++i) {
        cin >> s;
        int u, v, w;
        if (!id.count(s))id[s] = n++;
        u = id[s];
        cin >> s;
        if (!id.count(s))id[s] = n++;
        v = id[s];
        cin >> w;
        edge.push_back({u, v, w});
    }

    vector<vector<ii>> adj(n);
    for (auto [u, v, w]: edge)adj[u].push_back({v, w});
    vector<ll> dist(n, INF);
    vector<int> dist2(n);
    dist[0] = 0;
    dist2[0] = 0;
    priority_queue<tup, vector<tup>, greater<tup>> pq;
    pq.push({0, 0, 0});

    while (pq.size()) {
        auto [d, d2, u] = pq.top();
        pq.pop();
        if (dist[u] < d) continue;
        if (dist2[u] < d2) continue;
        for (auto [v, w] : adj[u]) {
            if (d + w < dist[v]) {
                dist[v] = d + w;
                dist2[v] = dist2[u] + 1;
                pq.push({dist[v], dist2[v], v});
            } else if (d + w == dist[v] && dist2[u] + 1 < dist2[v]) {
                dist2[v] = dist2[u] + 1;
                pq.push({dist[v], dist2[v], v});
            }
        }
    }
    cout << dist2[1] - 1 << endl;
}
