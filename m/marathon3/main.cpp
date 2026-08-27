#include <bits/stdc++.h>
using namespace std;
using ld = long double;

const ld EPS = 1e-9;

int main() {
    int n;
    cin >> n;
    vector<pair<ld, ld>> ints(n);
    ld lo = 0.0;
    ld hi = 1e12;
    for (auto &[a, b] : ints) {
        cin >> a >> b;
        if (a>b)swap(a,b);
        hi = min(hi, b);
    }
    while (hi - lo > EPS) {
        ld mid = (hi + lo) / 2;

        ld p = 0.0;

        for (auto [a, b] : ints) {
            if (b <= mid) {
                p = -10000;
                break;
            }
            if (a >= mid) continue;

            p += log((b - mid) / (b - a));
        }
        if (p >= log(0.5)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    cout << setprecision(10) << fixed << lo << endl;
}
