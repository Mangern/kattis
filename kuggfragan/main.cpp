#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e6+6;

vector<int> adj[mxN];
int n, m;

int col[mxN];

bool dfs(int u, int cf = -1) {
    for (int v : adj[u]) if (v != cf) {
        if (col[v]) {
            if (col[v] == col[u]) return false;
            continue;
        }
        col[v] = (col[u] == 1 ? 2 : 1);
        if (!dfs(v, u)) return false;
    }
    return true;
}


int main() {
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int u = 0; u < n; ++u) if (!col[u]) {
        col[u] = 1;
        if (!dfs(u)) {
            cout << "no way" << endl;
            return 0;
        }
    }

    cout << "attend here" << endl;
}
