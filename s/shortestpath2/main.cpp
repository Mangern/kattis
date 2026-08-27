#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll = long long;
using ii = array<ll,2>;

const int mxN = 1e4+87;
const ll INF = numeric_limits<ll>::max();

struct edge {
    int v;
    ll t0, p, w;
};

int n, m, q, s;
vector<edge> adj[mxN];
ll dist[mxN];

ll nxt(ll d, const edge& e) {
    if (e.p == 0) {
        if (d > e.t0)return -1;
        return e.t0;
    }

    // t0 + t * p >= d
    d -= e.t0;
    // t * p >= d
    // t >= (d / p)
    if (d <= 0)return e.t0;
    ll t = (d + e.p - 1) / e.p;
    return e.t0 + t * e.p;
}

int main() {
    while (cin >> n) {
        cin >> m >> q >> s;

        for (int i = 0; i < n; ++i) {
            adj[i].clear();
            if (i != s) {
                dist[i] = INF;
            } else {
                dist[i] = 0;
            }
        }
        for (int i = 0; i < m; ++i) {
            int u;
            edge e;
            cin >> u >> e.v >> e.t0 >> e.p >> e.w;
            adj[u].push_back(e);
        }


        priority_queue<ii, vector<ii>, greater<ii>> pq;
        pq.push({0, s});

        while (pq.size()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (dist[u] < d) continue;

            for (const auto& e : adj[u]) {
                ll tm = nxt(dist[u], e);
                if (tm == -1) continue;
                if (dist[e.v] > tm + e.w) {
                    dist[e.v] = tm + e.w;
                    pq.push({dist[e.v], e.v});
                }
            }
        }

        while (q-->0) {
            int u;
            cin >> u;
            ll d = dist[u];
            if (d == INF) cout << "Impossible" << endl;
            else {
                cout << d << endl;
            }
        }
    }
}
