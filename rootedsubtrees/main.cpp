#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 2e5+5;
const int K = 20;

int n, q;
int p[K][mxN];
int depth[mxN];
vector<int> adj[mxN];

void dfs(int u, int cf = -1) {
    p[0][u] = cf;
    for (int v : adj[u]) if (v != cf) {
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

int lca(int u, int v) {
    if (depth[u] > depth[v])swap(u, v);

    int d = depth[v] - depth[u];

    for (int k = 0; k < K; ++k) {
        if ((d >> k) & 1) v = p[k][v];
    }

    if (u == v) return u;

    for (int k = K - 1; k >= 0; --k) {
        if (p[k][u] != p[k][v]) {
            u = p[k][u];
            v = p[k][v];
        }
    }
    return p[0][u];
}

int dist(int u, int v) {
    int l = lca(u, v);

    return depth[u] + depth[v] - depth[l] - depth[l];
}

int main() {
    cin >> n >> q;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v, --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0);

    for (int k = 1; k < K; ++k) {
        for (int i = 0; i < n; ++i) {
            p[k][i] = p[k-1][p[k-1][i]];
        }
    }

    while (q-->0) {
        int u, v;
        cin >> u >> v, --u, --v;
        ll d = dist(u, v) + 1;

        cout << (d * (d + 1)) / 2 + n - d << endl;
    }
}
