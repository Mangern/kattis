#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 1e5+5;

ll n,d,q;
ll a[mxN];
ll num[mxN][6];
ll sum[mxN];
ll par[mxN];
vector<int> adj[mxN];

void dfs(int u, int cf = -1) {
    num[u][0] = 1;
    sum[u] += a[u];
    par[u] = cf;
    for (int v : adj[u]) if (v != cf) {
        sum[v] += sum[u];
        dfs(v, u);

        for (int k = 1; k <= d; ++k) {
            num[u][k] += num[v][k-1];
        }
    }
}

int main() {
    cin >> n >> d >> q;

    for (int i = 0; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v, --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(n);

    while (q-->0) {
        int u;
        cin >> u, --u;

        ll mul = a[u];

        ll ans = sum[u] + a[u];

        ll sub = 0;
        for (int i = 0; i <= d; ++i) {
            ll cur = 0;
            for (int j = 0; j <= d - i; ++j) {
                cur += num[u][j];
            }
            // cout << "Subtract " << cur - sub << " for " << u+1 << endl;
            // cout << "cur: " << cur << ", sub: " << sub << endl;
            ans -= (cur - sub) * mul;
            if (u == n) {
                // one too many!
                ans += mul;
                break;
            }
            sub=0;
            // next one is going to include us and our children
            for (int j = 0; j < d - i - 1; ++j) {
                sub += num[u][j];
            }
            u = par[u];
        }

        cout << ans << '\n';
    }
}
