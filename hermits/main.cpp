#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 1005;

ll n, m;
vector<int> adj[mxN];
ll a[mxN];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v, --u ,--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    ll anss = 1e15;

    for (int u = 0; u < n; ++u) {
        ll cur = a[u];
        for (int v : adj[u]) {
            cur += a[v];
        }

        if (cur < anss) {
            anss = cur;
            ans = u;
        }
    }
    cout << ans+1 << endl;
}
