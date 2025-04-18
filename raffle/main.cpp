#include <bits/stdc++.h>
using namespace std;
using ll = long long;

double evaluate(ll n, ll p, double m) {
    double prod = p * m / double(n + m);

    for (int i = 0; i < p - 1; ++i) {
        prod *= double(n - i) / double(n + m - 1 - i);
    }
    return prod;
}

int main() {
    ll n, p;
    cin >> n >> p;

    ll lo = 0;

    ll hi = n;

    while (hi - lo > 2) {
        ll lt = (2 * lo + hi) / 3;
        ll rt = (lo + 2 * hi) / 3;

        if (evaluate(n, p, lt) < evaluate(n, p, rt)) {
            lo = lt;
        } else {
            hi = rt;
        }
    }

    double ans = 0.0;

    for (ll i = lo; i <= hi; ++i) {
        ans = max(ans, evaluate(n, p, i));
    }

    cout << setprecision(8) << fixed << ans << endl;
}
