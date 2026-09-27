#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 1e5+5;

struct edge {
    ll u;
    ll v;
    ll l;
    ll spd1, spd2;
} edges[mxN];

ll n, m, t;
vector<int> adj[mxN];
double dist[mxN];

int main() {
    cin >> n >> m >> t;

    for (int i = 0; i < m; ++i) {
        edge& e = edges[i];
        cin >> e.u >> e.v >> e.l >> e.spd1 >> e.spd2;
        adj[e.u].push_back(i);
        adj[e.v].push_back(i);
    }

    using State = pair<double, ll>;
    for (int i = 2; i <= n; ++i) {
        dist[i] = numeric_limits<double>::infinity();
    }
    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({dist[1], 1});


    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (dist[u] < d) continue;

        for (int ei : adj[u]) {
            const edge& e = edges[ei];
            ll v = e.u ^ e.v ^ u;

            double w;
            if (d >= t) {
                w = (double)e.l / (double)e.spd2;
            } else {
                double t1 = e.l / (double)e.spd1;
                if (d + t1 <= t) {
                    w = t1;
                } else {
                    double rem_l = e.l - (t - d) * e.spd1;
                    assert(rem_l >= 0);
                    w = t - d + rem_l / (double)e.spd2;
                }
            }

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << setprecision(9) << fixed << dist[n] << endl;
}
