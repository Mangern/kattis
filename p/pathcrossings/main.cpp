#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    vector<array<ll, 4>> pts;
    ll p, n;
    cin >> p >> n;

    vector<array<ll, 2>> ans;

    for (ll i = 0; i < n; ++i) {
        ll p, x, y, t;
        cin >> p >> x >> y >> t;
        pts.push_back({t, p, x, y});
    }
    sort(begin(pts), end(pts));

    for (ll i = 1; i < n; ++i) {
        auto [ti, pi, xi, yi] = pts[i];
        for (ll j = i - 1; j >= 0; --j) {
            auto [tj, pj, xj, yj] = pts[j];
            if (pi == pj) continue;
            if (ti - tj > 10) break;
            if ((xi - xj) * (xi - xj) + (yi - yj) * (yi - yj) <= 1000000) {
                ans.push_back({min(pi, pj), max(pi, pj)});
            }
        }
    }
    sort(begin(ans), end(ans));
    ans.erase(unique(begin(ans), end(ans)), end(ans));
    cout << ans.size() << endl;
    for (auto [a, b] : ans)cout << a << " " << b << "\n";
}
