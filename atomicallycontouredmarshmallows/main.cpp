#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 3000;

int p[mxN];
ll nsets;

int find(int u) {
    if (p[u] == u) return u;
    return p[u] = find(p[u]);
}

bool join(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;
    p[u] = v;
    --nsets;
    return true;
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<array<ll, 3>> e;
    for (int i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        e.push_back({w,u,v});
    }

    iota(p,p+n,0);
    nsets=n;
    sort(begin(e), end(e));
    ll ans = 0;
    for (auto [w, u, v] : e) {
        if (join(u,v)) {
            ans += w;
        }
    }

    cout << (nsets == 1 ? ans : -1) << endl;
}
