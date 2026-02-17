#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const double INF = 3e8;
const double EPS = 1e-6;

int main() {
    ll n, l;
    cin >> n >> l;

    vector<ll> ds(n);
    vector<ll> ws(n);
    for (auto & d : ds) cin >> d;
    for (auto & w : ws) cin >> w;
    ds.push_back(l);

    double lo = 0.0;
    double hi = INF + EPS;

    while (hi - lo > EPS) {
        double v = (hi + lo) / 2.0;

        double t = 0.0;
        double prev = 0.0;
        for (int i = 0; i <= n; ++i) {
            t = max((double)ds[i], t + ((double)ds[i] - prev) / v);
            if (i < n) t += ws[i];
            prev = ds[i];
        }

        if (t == ds.back()) {
            hi = v;
        } else {
            lo = v;
        }
    }
    if (lo >= INF) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << setprecision(5) << fixed << lo << endl;
    }
}
