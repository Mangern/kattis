#include <bits/stdc++.h>
using namespace std;
using ld = long double;

const double EPS = 1e-9;

double spinter(const array<ld, 4> & sphere, ld zl, ld zh) {
    auto [r, x, y, z] = sphere;
    if (z + r <= zl || z - r >= zh) return 0.0;
    zl -= z;
    zh -= z;

    zl = max(zl, -r);
    zh = min(zh, r);

    return M_PI * (r * r * (zh - zl) - (zh*zh*zh-zl*zl*zl)/3.0);
}

int main() {
    int n, s;
    cin >> n >> s;

    ld w = 100 * 1000;
    ld h = w;
    ld d = w;

    ld vol = w * h * d;
    vector<array<ld, 4>> balls;

    for (int i = 0; i < n; ++i) {
        ld r, x, y, z;
        cin >> r >> x >> y >> z;

        balls.push_back({r, x, y, z});
        vol -= 4 * M_PI * r * r * r / 3;
    }

    ld dvol = vol / s;

    ld z = 0.0;

    for (int i = 0; i < s; ++i) {
        ld lo = z;
        ld hi = d;
        while (hi - lo > EPS) {
            ld mid = (hi + lo) / 2;

            ld v = (mid - z) * w * h;

            for (auto& b : balls) {
                v -= spinter(b, z, mid);
            }

            if (v < dvol) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        ld ans = (lo - z) / 1000;
        cout << setprecision(10) << fixed << ans << endl;
        z = lo;
    }
}
