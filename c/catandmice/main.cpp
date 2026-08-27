#include <algorithm>
#include <bits/stdc++.h>
#include <limits>
using namespace std;
#define FORMASK(i, mask) for (int _x = (mask), i; i = 31-__builtin_clz(_x&(-_x)), _x; _x -= (_x&-_x)) 

const double INF = numeric_limits<double>::infinity();
const int mxN = 15;

int n;

vector<int> ord;
double x[mxN];
double y[mxN];
double s[mxN];
double m;
// fastest way to visit all in mask and end at u
double dp[mxN][1<<mxN];

double solve(int u, int mask, double v) {
    double &r = dp[u][mask];

    double vr = v * pow(m, __builtin_popcount(mask) - 1);

    if (r != -1) return r;

    if (__builtin_popcount(mask) == 1) {
        double t = hypot(x[u], y[u]) / vr;
        if (t <= s[u]) return r = t;
        return r = INF;
    }


    r = INF;
    FORMASK(i, mask) if (i != u) {
        double t = hypot(x[i]-x[u], y[i] - y[u]) / vr;
        double alt = solve(i, mask ^ (1<<u), v) + t;
        if (alt <= s[u]) {
            r = min(r, alt);
        }
    }
    return r;
}

bool can(double v) {
    for (int i = 0; i < n; ++i) for (int j = 0; j < (1<<n); ++j) {
        dp[i][j] = -1;
    }

    for (int u = 0; u < n; ++u) {
        if (solve(u, (1<<n)-1, v) != INF)return true;
    }
    return false;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i] >> s[i];
    }

    vector<int> idx;
    idx.assign(n, 0);
    iota(begin(idx), end(idx), 0);

    cin >> m;

    double lo = 0;
    double hi = 1e10;

    while (hi - lo > 1e-5) {
        double mid = (lo + hi) / 2;

        if (can(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << setprecision(5) << fixed << lo << endl;
}
