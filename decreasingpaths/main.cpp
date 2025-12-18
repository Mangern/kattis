#include <bits/stdc++.h>
using namespace std;

const int mxN = 1<<17;

int grid[256][256];
vector<int> adj[mxN];
int lp[mxN];

int solve(int u) {
    if (lp[u] != -1) return lp[u];
    lp[u] = 1;
    for (int v : adj[u])lp[u] = max(lp[u], 1 + solve(v));
    return lp[u];
}

int main() {
    int r, c;
    cin >> r >> c;
    for (int i = 0; i < r;++i) {
        for (int j = 0; j < c; ++j) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            for (int ni = max(0, i - 1); ni <= min(i + 1, r - 1); ++ni) {
                for (int nj = max(0, j - 1); nj <= min(j + 1, c - 1); ++nj) {
                    if (grid[ni][nj] < grid[i][j]) {
                        adj[i*c + j].push_back(ni * c + nj);
                    }
                }
            }
        }
    }

    int n = r * c;
    memset(lp, -1, sizeof lp);
    int ans = 0;
    for (int i = 0; i < n; ++i) ans = max(ans, solve(i));
    cout << ans << endl;
}
