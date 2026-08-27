#include <bits/stdc++.h>
#include <limits>
#include <queue>
using namespace std;
using ll = long long;

const int mxN = 1e5+5;

using ii = array<ll, 2>;
using tup = array<ll, 4>;
const ll INF = numeric_limits<ll>::max();

// v, t0, p, d
ll n, m, s;
vector<tup> adj[mxN];
ll dist[mxN];

bool can(ll dep) {
    for (int i = 1; i < n; ++i) {
        dist[i] = INF;
    }
    dist[0] = dep;

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({dep, 0});

    while (pq.size()) {
        auto [curr_dist, u] = pq.top();
        pq.pop();

        if (dist[u] < curr_dist) continue;

        for (auto [v, t0, p, d] : adj[u]) {
            // t0 + k * p >= curr_dist
            // k * p >= curr_dist - t0
            // k >= (curr_dist - t0) / p
            ll k = max(0LL, (curr_dist - t0 + p - 1) / p);
            ll leave = t0 + k * p;

            if (dist[v] > t0 + k * p + d) {
                dist[v] = t0 + k * p + d;
                pq.push({dist[v], v});
            }
        }
    }

    return dist[n - 1] <= s;
}

int main() {
    cin >> n >> m >> s;

    for (int i = 0; i < m; ++i) {
        ll u, v, t0, p, d;
        cin >> u >> v >> t0 >> p >> d;

        adj[u].push_back({v,t0,p,d});
    }

    ll lo = -1;
    ll hi = s;

    while (lo < hi) {
        ll mid = (lo + hi + 1)/2;
        if (mid == -1) break;

        if (can(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    if (lo == -1) {
        cout << "impossible" << endl;
        return 0;
    }
    cout << lo << endl;
}
