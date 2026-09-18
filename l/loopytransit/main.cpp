#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;

    vector<vector<bool>> is_adj(n, vector<bool>(n, 0));

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        is_adj[u][v] = 1;
    }

    int ans = 0;
    for (int mask = 3; mask < (1<<n); ++mask) {
        if (__builtin_popcount(mask) <= 1) continue;
        vector<int> idx;
        for (int j = 0; j < n; ++j) if ((mask >> j) & 1) {
            idx.push_back(j);
        }
        do {
            int prv = -1;
            int fst = -1;
            bool ok=1;
            for (int u : idx) {
                if (prv == -1) {
                    fst = u;
                } else {
                    if (!is_adj[prv][u]) {
                        ok=0;
                        break;
                    }
                }
                prv = u;
            }
            if (!is_adj[prv][fst]) ok=0;

            if (ok) {
                ++ans;
            }
        } while (next_permutation(begin(idx)+1, end(idx)));
    }
    cout << ans << endl;
}
