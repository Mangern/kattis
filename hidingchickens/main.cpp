#include <bits/stdc++.h>
#include <limits>
using namespace std;

const int mxN = 20;
const double INF = numeric_limits<double>::infinity();

int n;
double dp[1<<mxN];
double xr, yr;
double x[mxN];
double y[mxN];

double solve(int mask) {
    if (mask == 0) {
        return dp[mask] = 0;
    }
    if (dp[mask] != INF) return dp[mask];

    for (int i = 0; i < mxN; ++i) if ((mask>>i)&1) {
        // only carry one
        dp[mask] = min(dp[mask], (1 + ((mask^(1<<i))>0)) * hypot(x[i],y[i])+solve(mask^(1<<i)));

        for (int j = i + 1; j < mxN; ++j) if ((mask >> j) & 1) {
            // carry two
            double dist = hypot(x[i],y[i])+hypot(x[j],y[j])+hypot(x[i]-x[j],y[i]-y[j]);

            if ((mask^(1<<i)^(1<<j)) == 0) {
                dist -= max(hypot(x[i],y[i]),hypot(x[j],y[j]));
            }

            dp[mask] = min(dp[mask], dist+solve(mask^(1<<i)^(1<<j)));
        }
    }
    return dp[mask];
}

int main() {

    for (int i = 0; i < (1<<mxN); ++i) {
        dp[i] = INF;
    }
    cin >> xr >> yr;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        x[i] -= xr;
        y[i] -= yr;
    }
    cout << setprecision(7) << fixed << solve((1<<n)-1) << endl;
    return 0;
}
