#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e4+5;

int n, m;

vector<int> adj[mxN];
int col[mxN];

void dfs(int u, int c = 1) {
    col[u] = c;

    for (int v : adj[u]) if (!col[v]) {
        dfs(v, c ^ 3);
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v, --u, --v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int u = 0; u < n; ++u) {
        if (!col[u])dfs(u);

        if (adj[u].empty()) {
            cout << "Impossible" << endl;
            return 0;
        }

    }

    for (int u = 0; u < n; ++u)
        cout << (col[u] == 1 ? "pub" : "house") << " ";
    cout << endl;
    return 0;
}
