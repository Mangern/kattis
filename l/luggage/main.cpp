#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    double l;
    cin >> n >> l;

    vector<double> pos(n);
    for (auto &x : pos) cin >> x;

    if (n == 1) {
        cout << 10 << endl;
        return 0;
    }

    sort(pos.begin(), pos.end());

    vector<pair<double, double>> ints;

    constexpr double EPS = 1e-10;
    constexpr double LB = 0.1-EPS, UB = 10.0+EPS;

    double nub = UB;
    for (int i = 1; i < n; ++i) {
        double d = pos[i] - pos[i-1];
        if (d < UB) {
            ints.push_back({d, UB});
            nub = min(nub, d);
        }
    }

    if (nub < 0.1) {
        cout << "no fika" << endl;
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            double d = pos[i] - pos[j];
            
            // d / v : Distance between i and j on the belt
            // d / v >= 1 -> v <= d

            double ub = nub;
            double lb = LB;

            // Illegal intervals: [d / (k * L + 1), d / (k * L - 1)]
            // d / (k * L + 1) <= ub
            // d <= ub * (k * L + 1)
            // k >= (d / ub - 1) / L ~ (d / 10 - 1) / L
            //
            // d / (k * L - 1) >= lb
            // d >= lb * (k * L - 1)
            // k <= (d / lb + 1) / L ~ (10 * d + 1) / L
            //
            // range k: (10 * d + 1) / L - (d / 10 - 1) / L
            //       =  (10 * d - d / 10 + 2) / L
            //       =  (d * 9.9 + 2) / L
            int kmin = max(1, (int)ceil((d / ub - 1) / l));
            int kmax = floor((d / lb + 1) / l);
            for (int k = kmin; k <= kmax; ++k) {
                ints.push_back({d / (k * l + 1), d / (k * l - 1)});
            }
        }
    }
    sort(ints.begin(), ints.end());

    double xptr = LB;
    double ans = 0.0;

    for (auto [l, r] : ints) {
        // cout << l << " " << r << endl;
        if (l > xptr && l < UB) {
            ans = l;
        }
        xptr = max(xptr, r);
    }

    if (ans < LB) {
        cout << "no fika" << endl;
    } else {
        cout << setprecision(10) << fixed << ans << endl;
    }
}
