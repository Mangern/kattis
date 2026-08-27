#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;

#define all(v) begin(v), end(v)

const int mxN = 1e5+4;

int n;
vi adj[mxN];
ll k[mxN];
ll dp[mxN];

void dfs_dp(int u) {
    dp[u] = k[u]+1;

    for (int v : adj[u]) {
        dfs_dp(v);
        dp[u] += dp[v];
    }

    sort(all(adj[u]), [&] (auto a, auto b) { return dp[a] < dp[b]; });
}

ll ans;
ll t;

void dfs_ans(int u) {
    t += 1; // read citation list u

    for (int v : adj[u]) {
        dfs_ans(v); // read v
    }
    // read u
    t += k[u];
    ans += t;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> k[i];

        int m;
        cin >> m;
        for (int j =0; j < m; ++j) {
            int v;
            cin >> v, --v;
            adj[i].push_back(v);
        }
    }

    dfs_dp(0);
    dfs_ans(0);

    cout << ans << endl;
}

