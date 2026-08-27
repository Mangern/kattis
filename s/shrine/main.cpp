#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct point {
    double x;
    double y;
};

void test() {
    ll w, n, d;
    cin >> w;
    if (!w) exit(0);
    cin >> n >> d;
    vector<ll> a(d);
    for (auto& x : a)cin >> x;

    vector<point> loc;
    for (ll i = 1; i <= n; ++i) {
        bool good = 0;
        for (auto x : a) {
            if (i % x == 0) {
                good = 1;
                break;
            }
        }
        if (!good) continue;

        double ang = 2*M_PI / (double)n * i;
        loc.push_back({1000.0*cos(ang), 1000.0*sin(ang)});
    }

    double lo = 0.0;
    double hi = 2 * M_PI * 1000;

    while (hi - lo > 1e-4) {
        double mid = (lo + hi) / 2.0;

        bool ok = 0;

        for (int i = 0; i < loc.size(); ++i) {
            int prv = i;
            int need = 1;
            double d = 0;
            for (int j = (i + 1) % loc.size(); j != i; j = (j + 1) % loc.size()) {
                d += hypot(loc[j].x - loc[prv].x, loc[j].y - loc[prv].y);
                if (d > mid) {
                    d = 0.0;
                    ++need;
                }
                prv = j;
            }

            if (need <= w) {
                ok = 1;
                break;
            }
        }

        if (ok) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    double ans = 2000.0 + lo;

    cout << setprecision(1) << fixed << round(10*ans)/10 << endl;
}

int main() {
    for (;;)test();
}
