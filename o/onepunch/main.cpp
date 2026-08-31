#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5+5;

int n, m, q;
string grid[mxN];
set<int> wall_adj[mxN];

struct UnionFind {
    vector<int> p, rnk;
    UnionFind(int n) {
        p.assign(n,0);
        iota(begin(p),end(p),0);
        rnk.assign(n,0);
    }

    int find(int i) {
        return p[i] == i ? i : (p[i] = find(p[i]));
    }

    void join(int i, int j) {
        i = find(i);
        j = find(j);
        if (i == j) return;

        if (rnk[i] > rnk[j]) {
            p[j] = i;
        } else {
            p[i] = j;
            if (rnk[i] == rnk[j]) {
                ++rnk[j];
            }
        }
    }
};

int main() {
    cin >> n >> m >> q;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    UnionFind uf(n * m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '.') {
                if (i > 0 && grid[i-1][j] == '.') {
                    uf.join(i * m + j, (i - 1) * m + j);
                }
                if (j > 0 && grid[i][j-1] == '.') {
                    uf.join(i * m + j, i * m + j - 1);
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] != '.') continue;
            int comp_here = uf.find(i * m + j);

            for (auto [ni, nj] : vector<pair<int,int>>{{i-2,j},{i+2,j},{i,j-2},{i,j+2}}) {
                if (ni < 0 || n <= ni || nj < 0 || m <= nj) continue;
                if (grid[ni][nj] != '.') continue;
                int mi = (i + ni) / 2;
                int mj = (j + nj) / 2;
                int comp_there = uf.find(ni * m + nj);
                if (comp_here != comp_there) {
                    wall_adj[comp_here].insert(comp_there);
                    wall_adj[comp_there].insert(comp_here);
                }
            }
            for (auto [ni, nj] : vector<pair<int,int>>{{i-1,j-1},{i-1,j+1},{i+1,j-1},{i+1,j+1}}) {
                if (ni < 0 || n <= ni || nj < 0 || m <= nj) continue;
                if (grid[ni][nj] != '.') continue;
                int comp_there = uf.find(ni * m + nj);
                if (comp_here != comp_there) {
                    wall_adj[comp_here].insert(comp_there);
                    wall_adj[comp_there].insert(comp_here);
                }
            }
        }
    }

    while (q-->0) {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        --a, --b, --c, --d;

        int u = uf.find(a * m + b);
        int v = uf.find(c * m + d);

        if (u == v || (k == 1 && wall_adj[u].count(v))) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
}
