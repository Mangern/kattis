#include <bits/stdc++.h>
using namespace std;

const int mxN = 55;

int n, m;
int depth[mxN];
int dp[mxN];
vector<int> adj[mxN];

void dfs(int u) {
    for (int v : adj[u]) {
        if (!depth[v]) {
            depth[v] = depth[u] + 1;
            dfs(v);
            dp[u] += dp[v];
        } else if (depth[v] < depth[u] - 1) {
            // back edge
            ++dp[u];
            --dp[v];
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    depth[1] = 1;
    dfs(1);

    vector<pair<int,int>> ans;
    for (int u = 1; u <= n; ++u) {
        if (u > 1 && (depth[u] == 0 || dp[u] == 0)) {
            cout << "NO" << endl;
            return 0;
        }
        for (int v : adj[u]) {
            if (depth[v] == depth[u] + 1 || depth[v] < depth[u] - 1) {
                ans.push_back({u, v});
            }
        }
    }
    cout << "YES" << endl;
    for (auto [u, v] : ans)cout << u << " " << v << endl;
}
