#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pop(m) __builtin_popcount(m)

const int mxN = 14;
const ll MOD = 1e9+7;

int n;
bool clique[1<<mxN];
int adj[mxN];

ll dp[1<<mxN];

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int g;
            cin >> g;

            adj[i] |= (g<<j);
        }
    }

    for (int i = 0; i < n; ++i) {
        clique[1<<i] = 1;
    }

    for (int mask = 1; mask < (1<<n); ++mask) if (pop(mask) > 1) {
        int rem = 31-__builtin_clz(mask);
        int sub = (mask ^ (1<<rem));
        if (!clique[sub]) continue;

        if ((adj[rem] & sub) == sub) {
            // rem adjacent to subset, subset is clique -> mask is clique
            clique[mask] = 1;
        }
    }

    dp[0] = 1;

    for (int mask = 1; mask < (1<<n); ++mask) {
        int u = 31-__builtin_clz(mask);
        int rem = mask ^ (1<<u);
        for (int subset = rem; subset >= 0; subset = (subset - 1) & rem) {
            int cl = subset | (1<<u);
            if (clique[cl]) {
                dp[mask] = (dp[mask] + dp[mask ^ cl]) % MOD;
            }
            if (subset == 0) break;
        }
    }

    cout << dp[(1<<n)-1] << endl;
}
