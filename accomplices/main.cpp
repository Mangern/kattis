#include <bits/stdc++.h>
using namespace std;
#define FORMASK(i, mask) for (int _x = (mask), i; i = 31-__builtin_clz(_x&(-_x)), _x; _x -= (_x&-_x)) 

int n, m;
int adj[21][21];
int ans[21];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v,--u,--v;
        adj[u][v] = adj[v][u] = 1;
    }

    for (int mask = 0; mask < (1<<n); ++mask) {
        bool good=1;
        FORMASK(i, mask) {
            FORMASK(j, mask) {
                if (i != j) {
                    if (adj[i][j]) {
                        good = 0;
                        break;
                    }
                }
            }
            if (!good)break;
        }
        if (good) {
            ++ans[__popcount(mask)];
        }
    }
    for (int i = 0; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
