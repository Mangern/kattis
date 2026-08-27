#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll = long long;
using ii = array<ll, 2>;
using ld = long double;

const ll INF = numeric_limits<ll>::max() / 4;

const int mxN = 2e5+5;

ll n,m,k;
vector<ii> adj[mxN];
ld p[mxN];
vector<ll> store;
ll dist[mxN];
ll dend[mxN];

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w, --u, --v;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    bool good = 0;
    for (int i = 0; i < k; ++i) {
        ll u;
        ld pr;
        cin >> u >> pr, --u;
        store.push_back(u);
        p[u] = pr;

        if (pr == 1.0) {
            good = 1;
        }
    }

    if (!good) {
        cout << "impossible" << endl;
        return 0.0;
    }

    for (ll i = 0; i < n; ++i) {
        dist[i] = INF;
        dend[i] = INF;
    }

    dist[0]   = 0;
    dend[n-1] = 0;

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, 0});

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

    pq.push({0, n - 1});

    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (dend[u] < d) continue;

        for (auto [v, w] : adj[u]) {
            if (dend[u] + w < dend[v]) {
                dend[v] = dend[u] + w;
                pq.push({dend[v], v});
            }
        }
    }

    sort(begin(store), end(store), [&](auto s1, auto s2) {
        return dist[s1]+dend[s1] < dist[s2] + dend[s2];
    });

    ld pprob = 1.0;

    ld ans = 0.0;

    ld mul = 1e5;

    for (int i = 0; i < k; ) {
        ll u = store[i];
        int j;
        ll cur = dist[u] + dend[u];
        for (j = i; j < k && dist[store[j]] + dend[store[j]] == cur; ++j);

        ld prod = 1.0;

        for (int z = i; z < j; ++z) {
            prod *= 1.0 - p[store[z]];
        }

        ans += pprob * mul * cur * (1.0 - prod);

        pprob *= prod;

        i = j;
    }

    ans /= mul;

    cout << setprecision(10) << fixed << ans << endl;
}
