#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll,2>;
using tup = array<ll,3>;
using tup4 = array<ll,4>;
using vi = vector<int>;

struct UnionFind {
    int num_sets;
    vi p, sz, rnk;
    UnionFind(int n) {
        num_sets = n;
        p = vi(n);
        iota(begin(p), end(p),0);
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

const int mxN = 1005;

int n, m;
vector<tup> adj[mxN];
vector<tup4> edges;
set<int> mst;
set<int> ans;
int p[mxN];

void dfs(int u, int cf = -1) {
    p[u] = cf;
    if (u == n - 1) return;

    for (auto [v, w, idx] : adj[u]) if (v != cf && mst.count(idx)) {
        dfs(v, u);
    }
}

int main() {
    cin >> n >> m;

    for (ll i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w, i});
        adj[v].push_back({u, w, i});
        edges.push_back({w, u, v, i});
    }

    sort(begin(edges), end(edges));
    reverse(begin(edges), end(edges));

    UnionFind uf(n);

    for (int i = 0; i < edges.size(); ++i) {
        auto [w, u, v, idx] = edges[i];
        if (uf.join(u, v)) {
            mst.insert(idx);
        }
    }

    dfs(0);

    int ptr = n - 1;

    vi path;

    while (ptr != 0) {
        path.push_back(ptr);
        ptr = p[ptr];
    }
    path.push_back(0);
    reverse(begin(path), end(path));

    for (int i = 0; i < path.size(); ++i) {
        int u = path[i];

        for (auto [v, w, idx] : adj[u]) {
            if (i > 0 && v == path[i-1]) continue;
            if (i < path.size() - 1 && v == path[i+1]) continue;
            ans.insert(idx);
        }
    }

    if (ans.empty()) {
        cout << "none" << endl;
        return 0;
    }

    for (auto x : ans)cout << x << " ";
    cout << endl;
}
