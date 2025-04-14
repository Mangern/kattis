#include <bits/stdc++.h>
#include <vector>
using namespace std;

void test() {
    int m;
    cin >> m;
    if (!m)exit(0);

    map<string, int> id;
    vector<pair<int,int>> pairs;
    int p = 0;

    for (int i = 0; i < m; ++i) {
        string s,t;
        cin >> s >> t;
        if (!id.count(s))id[s] = p++;
        if (!id.count(t))id[t] = p++;
        pairs.push_back({id[s], id[t]});
    }

    int n = id.size();
    vector<vector<int>> adj(n, vector<int>());

    for (auto [u,v] : pairs) {
        if (u>v)swap(u,v);
        adj[u].push_back(v);
    }

    vector<bool> dp(1<<n, false);
    dp[0] = 1;

    for (int mask = 1; mask < (1<<n); ++mask) {
        for (int u = 0; u < n; ++u) {
            if (!((mask>>u)&1)) continue;
            for (int v : adj[u]) {
                if (!((mask>>v)&1)) continue;
                for (int w : adj[v]) {
                    if (!((mask>>w)&1)) continue;
                    // u -> v -> w
                    //   ------>
                    if (find(begin(adj[u]), end(adj[u]), w) == end(adj[u])) continue;

                    dp[mask] = dp[mask] || dp[mask ^ (1<<u) ^ (1<<v) ^ (1<<w)];
                }
            }
        }
    }
    cout << (dp[(1<<n)-1] ? "possible" : "impossible") << endl;
}

int main() {
    for (;;)test();
}
