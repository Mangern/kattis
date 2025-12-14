#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll, 2>;

int main() {
    int n;
    cin >> n;
    vector<ii> trd(n);
    for (auto &[x, y] : trd) cin >> x >> y;

    sort(begin(trd), end(trd), [](auto a, auto b) {
        auto [g1,r1] = a;
        auto [g2,r2] = b;

        if (r1 * g2 == r2 * g1) {
            return r1 > r2;
        }

        return r1 * g2 > r2 * g1;
    });

    for (auto [x, y] : trd) cout << x << " " << y << "\n";
}
