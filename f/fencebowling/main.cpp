#include <bits/stdc++.h>
using namespace std;

int k;
double w, l;

pair<int, double> simulate(double beta) {
    double x = w * 0.5;
    double y = 0.0;
    double ang = beta;
    int hits = 0;
    int dir = 0;
    for (;;) {
        if (hits > k) return {hits, 0.0};

        if (dir == 0) {
            // left
            double dy = x * tan(ang);

            if (y + dy > l) {
                double ry = l - y;
                double dx = ry / tan(ang);
                return {hits, x - dx};
            }
            x = 0.0;
            y += dy;
        } else {
            // right
            double dy = (w - x) * tan(ang);

            if (y + dy > l) {
                double ry = l - y;
                double dx = ry / tan(ang);
                return {hits, x + dx};
            }

            x = w;
            y += dy;
        }

        ang = atan(2 * tan(ang));
        dir = !dir;
        ++hits;
    }
    return {1000, 0.0};
}

int main() {
    cin >> k >> w >> l;
    const double EPS = 1e-8;
    double lo = 0.0;
    double hi = M_PI/2;

    double x_goal = (double)w/2.0;

    while (hi - lo > EPS) {
        double mid = (lo + hi) / 2.0;

        auto [bounces, x_end] = simulate(mid);

        if (bounces < k) {
            // need to decrease 
            hi = mid;
        } else if (bounces > k) {
            lo = mid;
        } else {
            if (k & 1) {
                if (x_end < x_goal) {
                    hi = mid;
                } else {
                    lo = mid;
                }
            } else {
                if (x_end < x_goal) {
                    lo = mid;
                } else {
                    hi = mid;
                }
            }
        }
    }

    double ans = lo * 180.0 / M_PI;

    cout << setprecision(9) << fixed << ans << endl;
}
