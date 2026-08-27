#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = array<ll, 2>;

const int mxN = 105;

const ll INF = 1e9;

ll n, m, s, t, ans;
ll d1[mxN];
ll d2[mxN];

vector<ii> adj[mxN];

int main() {
    cin >> n >> m >> s >>t;

    --s, --t;

    for (int i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        --u, --v;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        ans += w;
    }

    for (int i = 0; i < n; ++i) {
        d1[i] = INF;
        d2[i] = INF;
    }

    priority_queue<ii, vector<ii>, greater<ii>> pq;

    d1[s] = 0;
    pq.push({0, s});

    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d1[u] < d) continue;

        for (auto [v, w]:adj[u]) {
            if (d1[u] + w < d1[v]) {
                d1[v] = d1[u] + w;
                pq.push({d1[v], v});
            }
        }
    }

    d2[t] = 0;
    pq.push({0, t});

    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d2[u] < d) continue;

        for (auto [v, w]:adj[u]) {
            if (d2[u] + w < d2[v]) {
                d2[v] = d2[u] + w;
                pq.push({d2[v], v});
            }
        }
    }

    ll len = d1[t];

    ll sub = 0;

    //for (int u = 0; u < n; ++u) {
    //    cout << d1[u] << endl;
    //}
    //for (int u = 0; u < n; ++u) {
    //    cout << d2[u] << endl;
    //}

    for (int u = 0; u < n; ++u) {
        for (auto [v, w] : adj[u]) {
            if (d1[u] + w + d2[v] == len) {
                sub += w;
            }
        }
    }
    cout << ans - sub << endl;
}
