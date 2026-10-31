#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> p, rnk;
    int num_sets;
    UnionFind(int n) {
        p.assign(n,0);
        iota(begin(p), end(p),0);
        rnk.assign(n,0);
        num_sets = n;
    }
    int find(int i) {
        return p[i] == i ? i : p[i] = find(p[i]);
    }
    void join(int i, int j) {
        i = find(i), j = find(j);
        if (i == j) return;
        --num_sets;

        if (rnk[i] > rnk[j]) {
            p[j] = i;
        } else {
            p[i] = j;
            if (rnk[i] == rnk[j])++rnk[j];
        }
    }
};

const int mxN = 1e4+5;

int adj[mxN];
int vis[mxN];
int cf[mxN];
bool incycle[mxN];
vector<int> child[mxN];

vector<int> cycle;

void dfs(int u) {
    vis[u] = 1;

    int v = adj[u];

    if (v == -1) {
        cycle.push_back(u);
        incycle[u] = 1;
    } else {
        if (vis[v] == 0) {
            cf[v] = u;
            dfs(v);
        } else if (vis[v] == 1) {
            // cycle
            cf[v] = u;
            int ptr = u;
            do {
                cycle.push_back(ptr);
                incycle[ptr] = 1;
                ptr = cf[ptr];
            } while (ptr != u);
            reverse(begin(cycle), end(cycle));
        }
    }

    vis[u] = 2;
}

void dfs_child(int u) {
    vis[u] = 1;
    int v = adj[u];

    if (v != -1) {
        if (!incycle[u]) {
            child[v].push_back(u);
        }
        if (!vis[v])dfs_child(v);
    }
}

int n;
vector<pair<int, char>> ans;
vector<string> grid;

void walk_tree(int u, int cf = -1) {
    int ui = u / n;
    int uj = u % n;
    for (int v : child[u]) {
        char c;
        int vi = v / n;
        int vj = v % n;
        if (vj == uj + 1) c = 'r';
        else if (vj == uj - 1) c = 'l';
        else if (vi == ui + 1) c = 'd';
        else if (vi == ui - 1) c = 'u';
        else assert(false);
        ans.push_back({1, c});
        walk_tree(v, u);
    }
    if (cf != -1) {
        ans.push_back({1, grid[ui][uj]});
    }
}

int main() {

    cin >> n;
    grid.resize(n);

    int rs, cs;
    cin >> rs >> cs, --rs, --cs;

    for (auto &s : grid) cin >> s;

    if (n == 1) {
        cout << "impossible" << endl;
        return 0;
    }

    UnionFind uf(n*n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int u = i * n + j;
            int v = -1;
            switch(grid[i][j]) {
                case 'r': if (j + 1 < n) v = i * n + j + 1; break;
                case 'd': if (i + 1 < n) v = (i + 1) * n + j; break;
                case 'u': if (i > 0) v = (i - 1) * n + j; break;
                case 'l': if (j > 0) v = i * n + j - 1; break;
            }
            adj[u] = v;
            if (v != -1)uf.join(u,v);
        }
    }
    if (uf.num_sets != 1) {
        cout << "impossible" << endl;
        return 0;
    }

    for (int u = 0; u < n * n; ++u) {
        if (!vis[u]) {
            dfs(u);
        }
    }
    memset(vis, 0, sizeof vis);
    for (int u = 0; u < n * n; ++u) {
        if (!vis[u]) dfs_child(u);
    }

    int endpos = -1;
    if (cycle.size() == 1) {
        int ui = cycle[0] / n;
        int uj = cycle[0] % n;
        for (int v : child[cycle[0]]) {
            int vi = v / n;
            int vj = v % n;

            if (grid[ui][uj] == grid[vi][vj]) {
                endpos = cycle[0];
                break;
            }
        }
    } else {
        int m = cycle.size();
        for (int i = 0; i < m; ++i) {
            int ui = cycle[i] / n;
            int uj = cycle[i] % n;
            int vi = cycle[(i+1)%m] / n;
            int vj = cycle[(i+1)%m] % n;
            if (grid[ui][uj] == grid[vi][vj]) {
                endpos = cycle[(i+1)%m];
                break;
            }
        }
    }
    if (endpos == -1) {
        cout << "impossible" << endl;
        return 0;
    }

    {
        int gi = endpos/n;
        int gj = endpos%n;

        if (rs < gi) {
            ans.push_back({gi-rs, 'd'});
        } else if (rs > gi) {
            ans.push_back({rs-gi, 'u'});
        }
        if (cs < gj) {
            ans.push_back({gj-cs, 'r'});
        } else if (cs > gj) {
            ans.push_back({cs-gj, 'l'});
        }
    }
    // we are now at endpos
    int ptr = endpos;
    for (;;) {
        walk_tree(ptr);
        int nxt = adj[ptr];
        if (nxt == -1) break;
        ans.push_back({1, grid[ptr/n][ptr%n]});
        if (nxt == endpos) break;
        ptr = nxt;
    }
    {
        vector<pair<int, char>> nans;
        for (auto [d, c] : ans) {
            if (nans.empty() || nans.back().second != c) {
                nans.emplace_back(d, c);
            } else {
                nans.back().first += d;
            }
        }
        swap(nans, ans);
    }

    cout << ans.size() << endl;
    for (auto [d, c] : ans) {
        cout << d << " " << c << endl;
    }
}
