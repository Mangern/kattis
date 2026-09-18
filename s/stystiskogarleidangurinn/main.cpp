#include <bits/stdc++.h>
#include <numeric>
using namespace std;
using ll = long long;

const int mxN = 16;
const ll INF = 1e9;

int n,m,s;
ll dp[mxN][1<<mxN];
ll dist[mxN][mxN];
vector<ll> extra;

ll tsp(int u, int mask) {
    ll &r = dp[u][mask];
    if (r != -1) return r;
    mask ^= (1<<u);
    if (mask == 0) return r = 0;

    r = INF;
    for (int v = 0; v < n; ++v) if ((mask >> v) & 1) {
        ll cur = dist[u][v] + tsp(v, mask);
        r = min(r, cur);
    }
    return r;
}

int main() {
    cin >> n >> m >> s;

    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        extra.push_back(x);
    }
    sort(begin(extra),end(extra));
    for (int i = 0; i < s; ++i) {
        extra.pop_back();
    }
    ll ans = accumulate(begin(extra), end(extra), 0LL);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dist[i][j] = INF;
            if (i == j) dist[i][j] = 0;
        }
    }

    for (int i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w, --u, --v;
        ll mn = dist[u][v];
        dist[u][v] = dist[v][u] = min(mn, w);
    }

    for (int i = 0; i < n; ++i) {
        memset(dp[i], -1, sizeof dp[i]);
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    ans += tsp(0, (1<<n)-1);

    cout << ans << endl;
}
