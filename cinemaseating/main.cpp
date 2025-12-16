#include <bits/stdc++.h>
using namespace std;

const int mxN = 1005;

int cnt[mxN][mxN];
int occ[mxN][mxN];

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < k; ++i) {
        int u, v;
        cin >> u >> v, --u, --v;

        occ[u][v] = 1;
        for (int nu = u - 1; nu <= u + 1; ++nu) {
            for (int nv = v - 1; nv <= v + 1; ++nv) {
                if (nu == u && nv == v) continue;
                if (nu < 0 || nu >= n || nv < 0 || nv >= m) continue;
                ++cnt[nu][nv];
            }
        }
    }

    int ans[9] = {0};

    for (int i =0 ; i < n; ++i) for (int j = 0; j < m; ++j) if (occ[i][j])++ans[cnt[i][j]];
    for (int i = 0; i < 9; ++i)cout << ans[i] << " \n"[i==8];
}
