#include <bits/stdc++.h>
#include <limits>
using namespace std;
using ll = long long;
// dst, cap, flow
using edge = tuple<int, ll, ll>;

const ll mxN = 5000;

const ll INF = 1e10;

ll n,q,s;
int src,tgt;

vector<edge> edges;
// idx in edge list
vector<int> adj[mxN];

int dist[mxN];
int last[mxN];

bool bfs() {
    memset(dist, -1, sizeof dist);
    queue<int> q;
    dist[src] = 0;
    q.push(src);

    while (q.size()) {
        int u = q.front(); q.pop();
        if (u == tgt) break;

        for (int& idx : adj[u]) {
            auto &[v, cap, flow] = edges[idx];
            if ((cap - flow > 0) && (dist[v] == -1)) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    return dist[tgt] != -1;
}

ll dfs(int u, ll f = INF) {
    if ((u == tgt) || (f == 0)) return f;

    for (int &i = last[u]; i < adj[u].size(); ++i) {
        auto &[v, cap, flow] = edges[adj[u][i]];
        if (dist[v] != dist[u] + 1) continue;
        if (ll bottle = dfs(v, min(f, cap - flow))) {
            flow += bottle;
            ll &rev = get<2>(edges[adj[u][i]^1]);
            rev -= bottle;
            return bottle;
        }
    }
    return 0;
}

ll max_flow() {
    ll mf = 0;

    while (bfs()) {
        memset(last, 0, sizeof last);
        while (ll flow = dfs(src)) {
            mf += flow;
        }
    }

    return mf;
}

int sensorid(int sensor, int wind) {
    return 1 + wind * s + sensor;
}

int queue_inid(int queue, int wind) {
    return sensorid(s-1, n-1) + 1 + 2 * wind * q + 2 * queue;
}

int queue_outid(int queue, int wind) {
    return sensorid(s-1, n-1) + 1 + 2 * wind * q + 2 * queue + 1;
}

void add_edge(int u, int v, ll cap) {
    edges.emplace_back(v, cap, 0);
    adj[u].push_back(edges.size() - 1);

    // rev
    edges.emplace_back(u, 0, 0);
    adj[v].push_back(edges.size() - 1);
}

int windid(int wind) {
    return queue_outid(q-1, n-1) + 1 + wind;
}

int main() {
    cin >> n >> q >> s;

    src = 0;
    tgt = windid(n);

    for (int i = 0; i < s; ++i) {
        int qi;
        cin >> qi, --qi;

        for (int j = 0; j < n; ++j) {
            add_edge(sensorid(i, j), queue_inid(qi, j), INF);
        }
    }

    for (int i = 0; i < q; ++i) {
        ll c;
        cin >> c;
        for (int j = 0; j < n; ++j) {
            add_edge(queue_inid(i, j), queue_outid(i, j), c);
            add_edge(queue_outid(i, j), windid(j), c);
            if (j < n - 1) {
                // for keeping stuff until the next window
                add_edge(queue_outid(i, j), queue_inid(i, j+1), c);
            }
        }
    }

    ll goal = 0;
    for (int w = 0; w < n; ++w) {
        ll d;
        cin >> d;
        add_edge(windid(w), tgt, d);

        for (int i = 0; i < s; ++i) {
            ll a;
            cin >> a;
            add_edge(src, sensorid(i, w), a);
            goal += a;
        }
    }
    cout << (max_flow() == goal ? "possible" : "impossible") << endl;
}
