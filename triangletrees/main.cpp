#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5+5;

int n, m;

int col[mxN];
vector<int> adj[mxN];

void dfs(int u) {
    int pos = 0b1110;
    for (int v : adj[u]) {
        pos &= (~(1<<col[v]));
    }
    int c = 1;
    while (!(pos & (1<<c)))++c;
    col[u] = c;

    for (int v : adj[u]) if (!col[v])dfs(v);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v, --u, --v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; ++i) {
        if (!col[i])dfs(i);

        cout << col[i] << " ";
    }
    cout << endl;

}
