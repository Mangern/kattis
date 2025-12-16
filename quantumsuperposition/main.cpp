#include <bits/stdc++.h>
using namespace std;
const int mxN = 1005;

int n1, n2, m1, m2;
vector<int> adj[2][mxN];

bool vis[2][mxN];
bool can[2][mxN][2*mxN];

void dfs(int u, int n, int t) {
    if (vis[t][u]) return;
    vis[t][u] = 1;

    if (u == n - 1) {
        can[t][u][0] = 1;
    }
    for (int v : adj[t][u]) {
        dfs(v, n, t);
        for (int k = 0; k <= 2000; ++k) {
            if (can[t][v][k]) {
                can[t][u][k+1] = 1;
            }
        }
    }
}

int main() {
    cin >> n1 >> n2 >> m1 >> m2;

    for (int i = 0; i < m1; ++i) {
        int u, v;
        cin >> u >> v, --u, --v;
        adj[0][u].push_back(v);
    }
    for (int i = 0; i < m2; ++i) {
        int u, v;
        cin >> u >> v, --u, --v;
        adj[1][u].push_back(v);
    }

    dfs(0, n1, 0);
    dfs(0, n2, 1);

    int q;
    cin >> q;


    while (q-->0) {
        int d;
        cin >> d;

        bool fail=1;
        for (int i = 0; i <= d; ++i) {
            if (can[0][0][i] && can[1][0][d-i]) {
                fail=0;
                break;
            }
        }

        if (fail) cout << "No\n";
        else cout << "Yes\n";
    }
}
