#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;

const int mxN = 1005;

int n,m;
vi adj[mxN];
int in[mxN];
bool good[mxN];
ll npath[mxN];
ll nwin[mxN];

void solve(int u) {
    if (npath[u] != -1) return;
    npath[u] = 0;
    nwin[u] = 0;
    if (good[u]) {
        nwin[u] = 1;
    }

    if (adj[u].empty())npath[u] = 1;

    for (int v : adj[u]) {
        solve(v);

        nwin[u] += nwin[v];
        npath[u] += npath[v];
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        ++in[v];
    }
    int k;
    cin >> k;

    for (int i = 0; i < k; ++i) {
        int u;
        cin >> u;
        good[u] = 1;
    }
    memset(npath, -1, sizeof nwin);

    ll win = 0;
    ll path = 0;
    for (int v = 0; v < n; ++v) if (!in[v]) {
        solve(v);
        win += nwin[v];
        path += npath[v];
    }

    cout << "winning paths " << win << endl;
    cout << "total paths " << path << endl;
}
