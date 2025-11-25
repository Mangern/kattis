#include <bits/stdc++.h>
using namespace std;

#define all(v) begin(v), end(v)

const int mxN = 5e5+5;
const int K = 20;

int n, k;
int p[K][mxN];

vector<int> child[mxN];

int par[mxN];
int ncyc = 1;
int cycid[mxN]; // id of cycle
int tim=1;
int vis[mxN];
int root[mxN]; // my nearest root
int droot[mxN];

int acc[mxN];
int ans[mxN];

vector<int> cycs[mxN];
int cycadd[mxN];
int cycacc[mxN];
int cycidx[mxN];
int cyclen[mxN];

void dfs(int u, int cf = -1) {
    int v = p[0][u];
    vis[u] = tim;
    par[u] = cf;
    if (vis[v]>0 && vis[v] != tim) return;

    if (vis[v]) {
        int p = u;
        par[v] = u;
        while (true) {
            cycs[ncyc].push_back(p);
            cycid[p] = ncyc;
            p = par[p];
            if (p == u) break;
        }
    } else {
        dfs(v, u);
    }
}

void dfstree(int i) {
    ans[i] += acc[i];
    for (int j : child[i]) if (cycid[j] == 0) {
        dfstree(j);
        ans[i] += ans[j];
    }
}

int kthboy(int i, int k) {
    for (int d = K - 1; d >= 0; --d) {
        if ((k >> d) & 1)i = p[d][i];
    }
    return i;
}

int main() {
    scanf("%d%d", &n, &k);

    memset(par, -1, sizeof par);

    for (int i = 0; i < n; ++i) {
        int j;
        scanf("%d", &j);
        --j;

        p[0][i] = j;
        child[j].push_back(i);
    }

    for (int k = 1; k < K; ++k) {
        for (int i = 0; i < n; ++i) {
            p[k][i] = p[k-1][p[k-1][i]];
        }
    }

    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            dfs(i);
            ++ncyc;
            ++tim;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (cycid[i] > 0) {
            root[i] =i;
            continue;
        }

        int u = i;

        int d = 0;

        for (int k = K - 1; k >= 0; --k) {
            if (cycid[p[k][u]]==0) {
                u = p[k][u];
                d |= (1<<k);
            }
        }
        root[i] = p[0][u];
        droot[i] = d + 1;
    }

    for (int c = 1; c < ncyc; ++c) {
        auto sz = cycs[c].size();
        cyclen[c] = sz;
        reverse(all(cycs[c]));

        for (int i = 0; i < sz; ++i) {
            cycidx[cycs[c][i]] = i;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (droot[i] > k) {
            // only in tree bruh
            acc[i]++;
            int j = kthboy(i, k);
            --acc[p[0][j]];
        } else {
            int r = root[i];
            int rem = k - droot[i];
            if (rem >= cyclen[cycid[r]]) {
                ++cycacc[cycs[cycid[r]][0]];
                // add to start node
                ++acc[i];
                // root is accounted for by cycacc
                --acc[r];
                continue;
            }

            ++acc[i];
            if (rem == 0)continue;

            --acc[r]; // accounted for by cycle


            int j = kthboy(r, rem);
            ++cycacc[r];

            if (cycidx[j] > cycidx[r]) {
                if (cycidx[p[0][j]] != 0) {
                    --cycacc[p[0][j]];
                }
            } else {
                ++cycacc[cycs[cycid[r]][0]];
                --cycacc[p[0][j]];
            }
        }
    }


    for (int i = 0; i < n; ++i) {
        if (root[i] == i)dfstree(i);
    }

    for (int c = 1; c < ncyc; ++c) {
        int a = 0;
        for (int u : cycs[c]) {
            a += cycacc[u];
            ans[u] += a;
            ans[u] += cycadd[c];
        }
    }

    for (int i = 0; i < n; ++i) {
        printf("%d\n", ans[i]);
    }
}
