#include <bits/stdc++.h>
using namespace std;

int main() {
    for (;;) {
        int n;
        cin >> n;
        if (!n) break;

        vector<pair<double, double>> pts(n);
        for (auto &[x, y] : pts) cin >> x >> y;

        auto eval = [&] (double xp) {
            double mdist = 0.0;
            for (auto [x, y] : pts) {
                mdist = max(mdist, hypot(x-xp, y));
            }
            return mdist;
        };

        double lo = -3e5;
        double hi = 3e5;
        const double EPS = 1e-10;

        while (hi - lo > EPS) {
            double m1 = lo + (hi - lo) * 1.0 / 3.0;
            double m2 = lo + (hi - lo) * 2.0 / 3.0;

            double s1 = eval(m1);
            double s2 = eval(m2);

            if (s1 <= s2) {
                hi = m2;
            } else {
                lo = m1;
            }
        }

        cout << setprecision(8) << fixed << lo << " " << setprecision(8) << fixed << eval(lo) << endl;
    }
}
