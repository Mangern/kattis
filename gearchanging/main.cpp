#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = array<ll, 2>;

int main() {
    vector<ii> ratios;
    ll n, m, p;
    cin >> n >> m >> p;

    vector<ll> a(n), b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    for (auto x : a) for (auto y : b) ratios.push_back({x, y});

    sort(begin(ratios), end(ratios), [] (auto r1, auto r2) {
        return r1[0] * r2[1] < r2[0] * r1[1];
    });

    for (int i = 0; i + 1 < ratios.size(); ++i) {
        auto [a, b] = ratios[i];
        auto [c, d] = ratios[i+1];

        // is a/b * (1 + p / 100) > c / d ?
        // is a * (1 + p / 100) > c * b / d ?
        // is a * d * (1 + p / 100) > c * b ?
        // is a * d + a * d * p / 100 > c * b ?
        // is 100 * a * d + a * d * p > 100 * c * b?
        if (100 * a * d + a * d * p < 100 * c * b) {
            cout << "Time to change gears!" << endl;
            return 0;
        }
    }
    cout << "Ride on!" << endl;
}
