#include <bits/stdc++.h>
using namespace std;

const int mxN = 5e4+5;

int n, m;
vector<int> adj[mxN];
vector<int> ans;
int vis[mxN];

void dfs(int u, int cf = -1) {
    vis[u] = 1;
    ans.push_back(u);
    for (int v : adj[u]) if (!vis[v]) {
        dfs(v, u);
        ans.push_back(u);
    } else if (vis[v] == 2) {
        ans.push_back(v);
        ans.push_back(u);
    }
    vis[u] = 2;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    for (auto u : ans)cout << u << " ";
    cout << endl;
}
