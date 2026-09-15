#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5+5;

int n, m;
vector<int> adj[mxN];
int dist[mxN];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(dist, -1, sizeof dist);

    dist[1] = 0;
    queue<int> q;
    q.push(1);

    while (q.size()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    cout << dist[n] - 1 << endl;
}
