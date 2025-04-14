#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll, 2>;
const ll INF = numeric_limits<ll>::max();

const int mxN = 1e4+5;

ll n, m, x;
vector<ii> adj[mxN];
ll shrt = 0;
ll dist[mxN];

void dijk(ll maxw) {
    dist[0] = 0;
    for (int i = 1; i < n; ++i) {
        dist[i] = INF;
    }

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, 0});

    while (pq.size()) {
        auto [d, u] = pq.top(); pq.pop();
        if (dist[u] < d) continue;

        for (auto [v, w] : adj[u]) if (w <= maxw) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

bool can(ll maxw) {
    double need = shrt + (shrt * (double)x) / 100.0;
    dijk(maxw);
    return dist[n-1] <= need;
}

int main() {
    cin >> n >> m >> x;

    ll big = 0;
    for (int i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w, --u, --v;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        big = max(big, w);
    }

    ll lo = 0;
    ll hi = big;
    dijk(big);
    shrt = dist[n - 1];

    while (lo < hi) {
        ll mid = (lo + hi) / 2;

        if (can(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo << endl;
}
