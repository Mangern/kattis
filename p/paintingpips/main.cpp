#include <bits/stdc++.h>
#include <cmath>
#include <numeric>
using namespace std;

#define all(v) begin(v), end(v)

using conf = array<int, 6>;

const int mxN = 21;
const int mxM = 101;

double dp[mxN][mxM];

double solve(int n, int m) {
    if (n < 0 || m < 0) {
        return 0.0;
    }
    if (n == 0) {
        return 1.0;
    }
    if (m == 0) {
        return 0.0;
    }
    if (m < n) {
        return 0.0;
    }

    if (dp[n][m] != -1.0) {
        return dp[n][m];
    }

    if (n == 1) {
        return dp[n][m] = (double)m / 6.0;
    }

    if (m == n) {
        return dp[n][m] = 1.0 / pow(6.0, m);
    }

    double &ret = dp[n][m];

    ret = 0.0;

    for (int p = 0; p < m; ++p) {
        if (m - p < n - 1) break;
        conf config = {0,0,0,0,0,p};
        double cur = 0.0;
        for (auto s : config) {
            cur += s * solve(n - 1, m  - p) / 6.0;
        }
        ret = max(ret, cur);
    }
    return ret;
}

int main() {
    for (int i = 0; i < mxN; ++i) {
        for (int j = 0; j < mxM; ++j) {
            dp[i][j] = -1.0;
        }
    }

    int n, m;
    cin >> n >> m;
    cout << setprecision(9) << fixed << solve(n, m) << endl;
}
