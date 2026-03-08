#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = numeric_limits<ll>::max() / 8;

const int mxN = 455;

struct state {
    ll d;
    ll node;
    ll n1;
    ll n2;

    bool operator<(const state& other) const {
        if (d == other.d) return node < other.node;
        return d > other.d;
    }
};

vector<array<ll, 3>> adj[mxN];

int main() {
    ll n, m, k1, k2;
    cin >> n >> m >> k1 >> k2;

    priority_queue<state> pq;

    vector<vector<vector<ll>>> dist(n, vector<vector<ll>>(k1+1, vector<ll>(k2+1, INF)));

    for (int i = 0; i < m; ++i) {
        ll u, v, c, w;
        cin >> u >> v >> w >> c, --u, --v;
        adj[u].push_back({v, w, c});
        adj[v].push_back({u, w, c});
    }
    ll s, t;
    cin >> s >> t, --s, --t;

    dist[s][0][0] = 0;
    pq.push(state{0, s, 0, 0});

    while (pq.size()) {
        auto [d, u, n1, n2] = pq.top();
        pq.pop();

        if (dist[u][n1][n2] < d) continue;

        for (auto [v, w, c] : adj[u]) {
            ll vn1 = n1 + (c == 1);
            ll vn2 = n2 + (c == 2);
            if (vn1 > k1) continue;
            if (vn2 > k2) continue;

            if (dist[v][vn1][vn2] > d + w) {
                dist[v][vn1][vn2] = d + w;
                pq.push(state{d + w, v, vn1, vn2});
            }
        }
    }

    ll ans = dist[t][k1][k2];
    if (ans == INF)ans = -1;
    cout << ans << endl;
}
