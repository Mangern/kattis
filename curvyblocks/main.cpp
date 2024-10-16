#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
using ld = long double;

const ld eps = 1e-9;

ld eval(ld x, ld a0, ld a1, ld a2, ld a3) {
    return a0 + a1 * x + a2 * x * x + a3 * x * x * x;
}

int main() {
    ld b0, b1, b2, b3;
    ld t0, t1, t2, t3;

    while (cin >> b0) {
        cin >> b1 >> b2 >> b3;
        cin >> t0 >> t1 >> t2 >> t3;

        ld a0 = t0 - b0;
        ld a1 = t1 - b1;
        ld a2 = t2 - b2;
        ld a3 = t3 - b3;

        ld mini = min(eval(0, a0, a1, a2, a3), eval(1, a0, a1, a2, a3));
        ld maxi = max(eval(0, a0, a1, a2, a3), eval(1, a0, a1, a2, a3));

        vector<ld> root;

        ld D = a2 * a2 - 3 * a1 * a3;
        if (D >= 0) {
            if (D < eps) {
                root.push_back(-a2 / (3 * a3));
            } else {
                root.push_back((-a2 + sqrtl(D))/(3*a3));
                root.push_back((-a2 - sqrtl(D))/(3*a3));
            }
        }

        for (ld r : root) {
            if (r < 0 || r > 1) continue;
            mini = min(mini, eval(r, a0, a1, a2, a3));
            maxi = max(maxi, eval(r, a0, a1, a2, a3));
        }

        cout << setprecision(7) << fixed << maxi - mini << endl;
    }

    return 0;
}
