#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll,2>;
using tup = array<ll, 3>;

const int mxN = 2005;

int n, m, s, t, g, h;
vector<ii> adj[mxN];
set<int> dests;
ii dist[mxN];

void testCase() {
    cin >> n >> m >> t;
    dests.clear();
    for (int i = 0; i < n; ++i) {
        adj[i].clear();
        dist[i] = {numeric_limits<ll>::max(), 1};
    }
    cin >> s >> g >> h;
    --g, --h, --s;


    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for (int i = 0; i < t; ++i) {
        int u;
        cin >> u, --u;
        dests.insert(u);
    }

    priority_queue<tup, vector<tup>, greater<tup>> pq;
    dist[s] = {0, 1};
    pq.push({0, 1, s});

    while (pq.size()) {
        auto [d, crossed, u] = pq.top();
        pq.pop();

        if (dist[u] < ii{d,crossed}) continue;

        for (auto [v, w] : adj[u]) {
            int ncross = crossed;
            if (crossed) {
                if (min(u,v) == min(g,h) && max(u,v) == max(g,h))ncross = 0;
            }
            ii nxt = {d + w, ncross};
            if (dist[v] > nxt) {
                dist[v] = nxt;
                pq.push({dist[v][0], dist[v][1], v});
            }
        }
    }

    for (auto x : dests) {
        if (!dist[x][1])cout << (x+1) << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-->0)testCase();
}
