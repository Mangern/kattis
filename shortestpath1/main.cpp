#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll,2>;

bool solve() {
    ll n, m, q, s;
    cin >> n >> m >> q >> s;
    if (!n)return false;

    vector<vector<ii>> adj(n, vector<ii>());

    for (int i = 0; i < m; ++i) {
        ll a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({w,b});
    }

    vector<ll> dist(n, numeric_limits<ll>::max());

    dist[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0,s});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (dist[u] < d)continue;

        for (auto [w, v] : adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d+w;
                pq.push({dist[v],v});
            }
        }
    }

    while (q-->0) {
        ll t;
        cin >> t;
        if (dist[t] == numeric_limits<ll>::max()) {
            cout << "Impossible" << endl;
        } else cout << dist[t] << endl;
    }
    return true;
}

int main() {
    while (solve()){}
}
