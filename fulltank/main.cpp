#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using ll = long long;
using ii = array<ll, 2>;

const int mxN = 1005;
const int mxK = 101;
const ll INF = numeric_limits<ll>::max() / 4;

ll n, m;

ll cost[mxN];
vector<ii> oadj[mxN];
vector<ii> adj[mxN * mxK];
ll dist[mxN * mxK];

struct el {
    ll d;
    ll u;
    bool operator<(const el& other) const {
        return d > other.d;
    }
};

int main() {
    scanf("%lld%lld", &n, &m);

    for (int i = 0; i < n; ++i) {
        scanf("%lld", &cost[i]);
    }

    for (int i = 0; i < m; ++i) {
        ll u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        oadj[u].push_back({v, w});
        oadj[v].push_back({u, w});
    }

    for (ll c = 0; c < mxK; ++c) {
        for (int u = 0; u < n; ++u) {
            for (auto [v, w] : oadj[u]) {
                if (w <= c) {
                    adj[c * n + u].push_back({(c - w) * n + v, 0});
                }
            }

            if (c < mxK - 1) {
                adj[c * n + u].push_back({(c + 1) * n + u, cost[u]});
            }
        }
    }
    int q;
    scanf("%d", &q);
    while (q-->0) {
        memset(dist, -1, sizeof dist);

        ll s, e, c;
        scanf("%lld%lld%lld", &c, &s, &e);

        __gnu_pbds::priority_queue<el> pq;
        dist[s] = 0;
        pq.push({0, s});

        while (pq.size()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dist[u] < d) continue;

            for (auto [v, w] : adj[u]) {
                ll cap = v / n;
                if (cap > c) continue;
                if (dist[v] == -1 || dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        ll ans = INF;

        for (int cv = 0; cv <= c; ++cv) {
            if (dist[cv * n + e] != -1)ans = min(ans, dist[cv * n + e]);
        }

        if (ans == INF) {
            printf("impossible\n");
        }
        else printf("%lld\n", ans);
    }
}
