#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5+5;
const int K = 18;

int n, c;
int p[K][mxN];
int depth[mxN];
vector<int> adj[mxN];
int w[mxN];
int h[mxN];
int start[mxN];
bool active[mxN];
int parent[mxN];
int vis[mxN];

void dfs(int u, int cf = -1, int d = 0, int nearest_w = -1) {
    depth[u] = d;
    parent[u] = nearest_w;
    for (int v : adj[u]) if (v != cf) {
        dfs(v, u, d+1, start[u] == -1 ? nearest_w : u);
        p[0][v] = u;
    }
}

int lca(int u, int v) {
    if (depth[u] > depth[v])swap(u, v);

    int diff = depth[v] - depth[u];
    for (int k = 0; k < K; ++k) {
        if (diff & (1<<k)) {
            v = p[k][v];
        }
    }

    if (u == v)return u;

    for (int k = K - 1; k >= 0; --k) {
        if (p[k][u] != p[k][v]) {
            u = p[k][u];
            v = p[k][v];
        }
    }

    return p[0][u];
}

int find_p(int u) {
    if (u != -1) 
        assert(start[u] != -1);
    return (u == -1 || vis[start[u]] <= 1) ? u : parent[u] = find_p(parent[u]);
}

int md[mxN];
int middle_dest(int i) {
    if (md[i] != -1)return md[i];
    int u = w[i];
    int v = h[i];

    return md[i] = lca(u,v);
}

vector<int> topo;

void dfs_dag(int u) {
    if (vis[u] == 2)return;
    //cout << u+1 << endl;
    if (vis[u] == 1) {
        cout << "No" << endl;
        exit(0);
        return;
    }

    vis[u] = 1;

    while (true) {
        int p = find_p(parent[w[u]]);

        if (p != -1 && depth[p] >= depth[middle_dest(u)]) {
            //cout << "Clear " << start[p]+1 << " before " << u+1 << endl;
            dfs_dag(start[p]);
        } else break;
    }

    if (start[h[u]] != -1) {
        //cout << "Clear " << start[h[u]]+1 << " before " << u+1 << endl;
        dfs_dag(start[h[u]]);
    }

    while (true) {
        int p = find_p(parent[h[u]]);

        if (p != -1 && depth[p] > depth[middle_dest(u)]) {
            //cout << "Clear " << start[p]+1 << " before " << u+1 << endl;
            dfs_dag(start[p]);
        } else break;
    }

    topo.push_back(u);

    vis[u] = 2;
}

int main() {
    memset(start, -1, sizeof start);
    memset(md, -1, sizeof md);
    cin >> n >> c;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v, --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < c; ++i) {
        cin >> w[i] >> h[i], --w[i], --h[i];

        start[w[i]] = i;
    }

    dfs(0);

    for (int k = 1; k < K; ++k) {
        for (int i = 0; i < n; ++i) {
            p[k][i] = p[k-1][p[k-1][i]];
        }
    }

    for (int i = 0; i < c; ++i) if (!vis[i]) {
        dfs_dag(i);
    }

    if (topo.size() != c) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    for (auto i : topo)cout << i+1 << " ";
    cout << endl;

    return 0;
}
