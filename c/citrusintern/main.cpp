#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 1e5+5;

ll cost[mxN];
ll dp[mxN][2][2];
vector<int> child[mxN];

ll dfs(int u, int par_bribed = 0, int par_covered = 1) {
    ll& ans = dp[u][par_bribed][par_covered];
    if (ans != -1) {
        return ans;
    }
    if (par_bribed) {
        // Cannot bribe here
        ll ret = 0;
        for (auto v : child[u]) {
            // My parent was bribed so I am covered
            ret += dfs(v, 0, 1);
        }
        return ans = ret;
    } else {
        if (par_covered) {
            // I can decide if I want to bribe or not
            ll ret = cost[u];
            for (auto v : child[u]) {
                ret += dfs(v, 1, 1);
            }

            // If I am not bribed I have to be covered
            // by one child. But the other ones don't need to cover me
            vector<ll> cost_nocover(child[u].size(), 0);
            ll sm_nocover = 0;
            for (int i = 0; i < child[u].size(); ++i) {
                cost_nocover[i] = dfs(child[u][i], 0, 1);
                sm_nocover += cost_nocover[i];
            }
            for (int i = 0; i < child[u].size(); ++i) {
                ll cost_cover = dfs(child[u][i], 0, 0);
                ret = min(ret, cost_cover + sm_nocover - cost_nocover[i]);
            }
            return ans = ret;
        } else {
            // I have to be bribed
            ll ret = cost[u];

            for (auto v : child[u]) {
                ret += dfs(v, 1, 1);
            }
            return ans = ret;
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<bool> has_par(n,false);
    for (int i = 0; i < n; ++i) {
        dp[i][0][0] = -1;
        dp[i][0][1] = -1;
        dp[i][1][0] = -1;
        dp[i][1][1] = -1;

        cin >> cost[i];
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int v;
            cin >> v;
            child[i].push_back(v);
            has_par[v] = 1;
        }
    }

    int root;
    for (root = 0; root < n; ++root) {
        if (!has_par[root]) break;
    }
    cout << dfs(root) << endl;
}
