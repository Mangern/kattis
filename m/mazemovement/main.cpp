#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 1e3+5;

struct MaxFlow {
    using edge = array<ll, 3>;
    static const ll INF = 1e10;
    vector<edge> edges;
    vector<vector<int>> adj;
    vector<int> last;
    vector<int> dist;
    int n;

    MaxFlow(int n) : n(n) {
        adj.assign(n, vector<int>());
    }

    void add_edge(ll u, ll v, ll cap, bool directed = true) {
        edges.push_back({v, cap, 0LL});
        adj[u].push_back(edges.size() - 1);
        edges.push_back({u, directed ? 0LL : cap, 0LL});
        adj[v].push_back(edges.size() - 1);
    }

    bool bfs(int s, int t) {
        dist.assign(n, -1);
        dist[s] = 0;
        queue<int> q({s});
        while (q.size()) {
            int u = q.front(); q.pop();
            if (u == t) break;

            for (int &idx : adj[u]) {
                auto &[v,cap,flow] = edges[idx];
                if (cap - flow > 0 && dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return dist[t] != -1;
    }

    ll dfs(int u, int t, ll f = INF) {
        if (u == t || f == 0) return f;

        for (int &i = last[u]; i < adj[u].size(); ++i) {
            auto &[v, cap, flow] = edges[adj[u][i]];
            if (dist[v] != dist[u] + 1) continue;
            if (ll bottle = dfs(v, t, min(f, cap - flow))) {
                flow += bottle;
                ll &rev_flow = edges[adj[u][i]^1][2];
                rev_flow -= bottle;
                return bottle;
            }
        }

        return 0;
    }

    ll max_flow(int s, int t) {
        ll mf = 0;
        while (bfs(s,t)) {
            last.assign(n, 0);
            while (ll flow = dfs(s, t)) {
                mf += flow;
            }
        }
        return mf;
    }
};

int n;
ll a[mxN];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    MaxFlow mf(n);

    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (gcd(a[i], a[j]) > 1) {
                mf.add_edge(i, j, gcd(a[i], a[j]), false);
            }
        }
    }

    int s = min_element(a, a+n)-a;
    int t = max_element(a, a+n)-a;
    cout << mf.max_flow(s, t) << endl;
}
