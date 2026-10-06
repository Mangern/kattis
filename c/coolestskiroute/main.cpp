#include <bits/stdc++.h>
using namespace std;

const int mxN = 1005;

int n, m;
vector<pair<int,int>> adj[mxN];
int dp[mxN];

int search(int u) {
    if (dp[u] != -1) return dp[u];
    dp[u] = 0;
    for (auto [v, w] : adj[u]) {
        dp[u] = max(dp[u], w + search(v));
    }
    return dp[u];
}

int main() {
    cin >> n >> m;

    memset(dp, -1, sizeof dp);
    for (int i = 0; i < m; ++i) {
        int u, v,  w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }

    int ans = 0;
    for (int u = 1; u <= n; ++u) {
        ans = max(ans, search(u));
    }
    cout << ans << endl;
}
