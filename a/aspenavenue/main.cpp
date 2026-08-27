#include <bits/stdc++.h>
#include <cmath>
#include <iomanip>
#include <limits>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using ld = long double;

const int mxN = 1003;

ll n, L, W;

ld dp[mxN][mxN];
ld p[mxN<<1];

ld solve(int l, int r) {
    if (l == 0 && r == 0)return 0.0;

    if (dp[l][r] != -1.0)return dp[l][r];

    ld py = p[l+r-1];

    ld ply = ((ld)(l - 1) * L / (ld(n/2-1)));
    ld plx = 0;
    ld pry = ((ld)(r - 1) * L / (ld(n/2-1)));
    ld prx = W;

    ld alt1 = numeric_limits<ld>::max();
    ld alt2 = numeric_limits<ld>::max();

    if (l > 0) {
        alt1 = solve(l - 1, r) + abs(ply - py);
    }
    if (r > 0) {
        alt2 = solve(l, r - 1) + sqrtl(prx * prx + (pry - py) * (pry - py));
    }

    dp[l][r] = min(alt1, alt2);
    return dp[l][r];
}

int main() {
    cin >> n >> L >> W;

    for (int i = 0; i <= n/2; ++i) for (int j = 0; j <= n / 2; ++j) {
        dp[i][j] = -1.0;
    }


    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    sort(p, p+n);

    cout << setprecision(8) << fixed << solve(n/2, n/2) << endl;

    return 0;
}

