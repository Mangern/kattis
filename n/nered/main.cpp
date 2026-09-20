#include <bits/stdc++.h>
using namespace std;

const int mxN = 101;

int grid[mxN][mxN];
int pref[mxN][mxN];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int r,c;
        cin >> r >> c, --r, --c;
        ++grid[r][c];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + (grid[i-1][j-1] == 0);
        }
    }

    int ans = INT_MAX;
    for (int r = 1; r <= m; ++r) {
        if (m % r != 0) continue;
        int c = m / r;

        for (int t = 0; t + r <= n; ++t) {
            for (int l = 0; l + c <= n; ++l) {
                int nz = pref[t+r][l+c] - pref[t+r][l] - pref[t][l+c] + pref[t][l];
                ans = min(ans, nz);
            }
        }
    }
    cout << ans << endl;
}
