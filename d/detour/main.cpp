#include <bits/stdc++.h>
#include <limits>
#include <queue>
using namespace std;
using ll = long long;
using ii = array<ll,2>;

const int mxN = 1e5+5;

const ll INF = numeric_limits<ll>::max() / 4;

int n, m;

vector<ii> adj[mxN];
vector<ii> nadj[mxN];
ll dist[mxN];
ll ndist[mxN];
int par[mxN];
int npar[mxN];

int main() {

    cin >> n >> m;
    for (int i = 0; i < m ; ++i) {
        ll u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    for (int i = 0; i < n; ++i) {
        dist[i] = INF;
        ndist[i] = INF;
    }

    dist[1] = 0;
    par[1] = 1;

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, 1});

    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (dist[u] < d) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                par[v] = u;
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (auto [j, w] : adj[i]) {
            if (j != par[i]) {
                nadj[i].push_back({j, w});
            }
        }
    }

    pq.push({0, 0});
    npar[0] = -1;
    ndist[0] = 0;

    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (ndist[u] < d) continue;

        for (auto [v, w] : nadj[u]) {
            if (ndist[u] + w < ndist[v]) {
                npar[v] = u;
                ndist[v] = ndist[u] + w;
                pq.push({ndist[v], v});
            }
        }
    }

    if (ndist[1] == INF) {
        cout << "impossible" << endl;
        return 0;
    }

    vector<int> path;

    int ptr = 1;

    while (ptr != -1) {
        path.push_back(ptr);
        ptr = npar[ptr];
    }

    reverse(begin(path), end(path));

    cout << path.size();

    for (auto p : path)cout << " " << p;
    cout << endl;
}
