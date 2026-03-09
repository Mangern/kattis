#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using vi = vector<int>;

#define sz(v) ((int)(v).size())
#define all(v) begin(v), end(v)

const int mxN = 301;

struct UnionFind {
    int num_sets;
    vi p, sz, rnk;
    UnionFind(int n) {
        num_sets = n;
        p = vi(n);
        iota(all(p),0);
        rnk = vi(n,0);
        sz = vi(n,1);
    }

    int find(int i) {
        if (p[i] == i)return i;
        return p[i] = find(p[i]);
    }

    bool check(int i, int j) {
        return find(i)==find(j);
    }

    bool join(int i, int j) {
        i = find(i);
        j = find(j);
        if (i == j)return 0;
        if (rnk[i] < rnk[j]) {
            sz[j] += sz[i];
            p[i] = j;
        } else {
            sz[i] += sz[j];
            p[j] = i;
            if (rnk[i] == rnk[j]) {
                ++rnk[i];
            }
        }
        --num_sets;
        return 1;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        uf.join(u, v);
    }

    vector<int> comps;

    for (int i = 0; i < n; ++i) {
        if (uf.find(i) == i)comps.push_back(i);
    }
    sort(begin(comps), end(comps));

    auto getcomp = [&] (int i) {
        return lower_bound(begin(comps), end(comps), i) - begin(comps);
    };
    int c = comps.size();

    vector<vector<ll>> dist(c, vector<ll>(c, numeric_limits<ll>::max() / 8));
    for (int i = 0; i < c; ++i)dist[i][i] = 0;

    ll f;
    cin >> f;

    for (int i = 0; i < f; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;

        u = uf.find(u);
        v = uf.find(v);
        if (u == v) continue;

        u = getcomp(u);
        v = getcomp(v);
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }

    for (int k = 0; k < c; ++k) {
        for (int u = 0; u < c; ++u) {
            for (int v = 0; v < c; ++v) {
                dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
            }
        }
    }

    int q;
    cin >> q;

    ll ans = 0;
    while (q-->0) {
        ll u, v;
        cin >> u >> v;
        u = getcomp(uf.find(u));
        v = getcomp(uf.find(v));
        ans += dist[u][v];
    }
    cout << ans << endl;
}
