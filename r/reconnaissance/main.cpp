#include <bits/stdc++.h>
#include <limits>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    for (auto& [x, v] : a) cin >> x >> v;

    double lo = 0.0;
    double hi = 2e5;

    const double EPS = 1e-5;

    auto eval = [&](double t) {
        double xmin = numeric_limits<double>::infinity();
        double xmax = -xmin;

        for (auto [x, v] : a) {
            double pos = x + v * t;
            xmin = min(xmin, pos);
            xmax = max(xmax, pos);
        }
        return xmax - xmin;
    };

    while (hi - lo > EPS) {
        double t1 = lo + (hi - lo) * 1.0 / 3.0;
        double t2 = lo + (hi - lo) * 2.0 / 3.0;

        double d1 = eval(t1);
        double d2 = eval(t2);

        if (d1 < d2) {
            hi = t2;
        } else {
            lo = t1;
        }
    }

    cout << setprecision(5) << fixed << eval(lo) << endl;
}
