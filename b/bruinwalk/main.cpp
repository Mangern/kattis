#include <bits/stdc++.h>
using namespace std;

const int mxN = 1005;

int n, m;
vector<int> adj[mxN];
int s, t;
int dist[mxN];

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cin >> s >> t;


    for (int i = 1; i <= n; ++i) {
        dist[i] = INT_MAX;
    }
    dist[t] = 0;
    queue<int> q;
    q.push(t);
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    int mdist = INT_MAX;
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int u;
        cin >> u;
        mdist = min(mdist, dist[u]);
    }

    if (dist[s] < mdist)cout << "YES" << endl;
    else cout << "NO" << endl;
}
