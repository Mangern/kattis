#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> f(n,0);
    vector<ll> lose(n, 0);
    for (auto &x : f) cin >> x;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v, --u, --v;

        if (f[u] == 0) {
            lose[u] += f[v];
        }
        if (f[v] == 0) {
            lose[v] += f[u];
        }
    }
    sort(rbegin(lose), rend(lose));
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        ans += lose[i] * i;
    }
    cout << ans << endl;
}
