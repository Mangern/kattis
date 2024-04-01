#include <bits/stdc++.h>
#include <climits>
using namespace std;
using ll = long long;

const int mxN = 501;

int n;
ll W;
ll A[mxN][mxN];
ll B[mxN][mxN];
vector<ll> weight[mxN][mxN];
ll maxminweight[mxN][mxN];
ll minmaxweight[mxN][mxN];

struct UnionFind {
    vector<int> p;
    vector<int> rank;

    UnionFind(int n) {
        p = vector<int>(n, 0);
        iota(begin(p), end(p), 0);
        rank = vector<int>(n, 0);
    }

    int find(int i) {
        if (i == p[i])return i;
        return p[i] = find(p[i]);
    }

    bool join(int i, int j) {
        i = find(i);
        j = find(j);
        if (i == j)return false;

        if (rank[i] > rank[j]) {
            p[j] = i;
        } else {
            p[i] = j;
            if (rank[i] == rank[j])++rank[j];
        }
        return true;
    }
};

vector<array<int,3>> spantree(vector<array<int,3>> edges, bool maximize = false) {
    sort(edges.begin(), edges.end(), [&] (auto a, auto b) {
        return a[2] < b[2];
    });
    if (maximize) {
        reverse(edges.begin(), edges.end());
    }

    UnionFind uf(n);
    vector<array<int,3>> tree;

    for (auto [u, v, w] : edges) {
        if (uf.join(u,v)) {
            tree.push_back({u,v,w});
        }
    }
    return tree;
}

int main() {
    cin >> n >> W;

    ll Cs, Bs;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            ll C;
            cin >> C;
            A[j][i] = W - C;
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            cin >> B[j][i];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            maxminweight[i][j] = -INT_MAX;
            minmaxweight[i][j] = INT_MAX;
        }
    }

    vector<array<int,3>> edges;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (A[i][j] > B[i][j])continue;
            //maxminweight[i][j] = max(maxminweight[i][j], A[i][j]);
            //maxminweight[i][j] = max(maxminweight[i][j], B[i][j]);
            //maxminweight[j][i] = max(maxminweight[j][i], A[i][j]);
            //maxminweight[j][i] = max(maxminweight[j][i], B[i][j]);

            //minmaxweight[i][j] = min(minmaxweight[i][j], A[i][j]);
            //minmaxweight[i][j] = min(minmaxweight[i][j], B[i][j]);
            //minmaxweight[j][i] = min(minmaxweight[j][i], A[i][j]);
            //minmaxweight[j][i] = min(minmaxweight[j][i], B[i][j]);

            edges.push_back({i, j, (int)A[i][j]});
            edges.push_back({i, j, (int)B[i][j]});

        }
    }

    auto minst_edges = spantree(edges, false);
    auto maxst_edges = spantree(edges, true);

    edges.clear();

    set<array<int,3>> processed;

    for (auto [i, j, b] : minst_edges) {
        maxminweight[i][j] = max(maxminweight[i][j], (ll)b);
        maxminweight[j][i] = max(maxminweight[j][i], (ll)b);

        minmaxweight[i][j] = min(minmaxweight[i][j], (ll)b);
        minmaxweight[j][i] = min(minmaxweight[j][i], (ll)b);

        edges.push_back({i, j, (int)b});
        processed.insert({i,j,b});
    }
    for (auto [i, j, b] : maxst_edges) {
        if (processed.count({i,j,b}))continue;
        maxminweight[i][j] = max(maxminweight[i][j], (ll)b);
        maxminweight[j][i] = max(maxminweight[j][i], (ll)b);

        minmaxweight[i][j] = min(minmaxweight[i][j], (ll)b);
        minmaxweight[j][i] = min(minmaxweight[j][i], (ll)b);

        edges.push_back({i, j, (int)b});
    }


    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                maxminweight[i][j] = max(maxminweight[i][j], 
                        min(maxminweight[i][k], maxminweight[k][j]));
                minmaxweight[i][j] = min(minmaxweight[i][j], 
                        max(minmaxweight[i][k], minmaxweight[k][j]));
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            //cout << maxminweight[i][j] << endl;
            if (maxminweight[i][j] == -INT_MAX || minmaxweight[i][j] == INT_MAX 
                    || maxminweight[i][j] != B[i][j] || minmaxweight[i][j] != A[i][j]) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << edges.size() << endl;
    for (auto [u, v, b] : edges) {
        cout << u << " " << v << " " << b << endl;
    }
}
