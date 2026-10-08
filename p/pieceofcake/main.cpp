#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define all(v) begin(v), end(v)

const int mxN = 2505;
const int K = 22;

struct Point {
    double x;
    double y;
};

int n, k;

Point points[mxN];


int main() {
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    ld ans = 0.0;

    double total_area = 0.0;

    {
        auto [x0, y0] = points[0];
        for (int j = 2; j != 0; j = (j + 1) % n) {
            auto [xj, yj] = points[j];
            auto [xp, yp] = points[(j-1+n)%n];
            xj -= x0;
            yj -= y0;
            xp -= x0;
            yp -= y0;
            total_area += 0.5 * (xj * yp - xp * yj);
        }
    }

    ld p_init = 1.0;

    for (int i = 1; i <= n; ++i) {
        p_init /= i;
        if (i <= k)p_init *= i;
        if (i <= n - k)p_init *= i;
        if (i <= n - 2)p_init *= i;
        if (i <= k - 2)p_init /= i;
        if (i <= (n-2) - (k-2))p_init /= i;
    }

    for (int i = 0; i < n; ++i) {
        double area_left = 0.0;
        int pts_right = n - 2;
        ld p = p_init;
        auto [xi, yi] = points[i];
        for (int j = (i + 1) % n; j != i; j = (j + 1) % n) {
            if (pts_right < k - 2) break;
            if (j != (i + 1) % n) {
                auto [xj, yj] = points[j];
                auto [xp, yp] = points[(j-1+n)%n];
                xj -= xi;
                yj -= yi;
                xp -= xi;
                yp -= yi;

                area_left += 0.5 * (xj * yp - xp * yj);
            }

            ans += area_left * p;

            p /= pts_right;
            p *= pts_right - (k - 2);

            --pts_right;
        }
    }

    ans = total_area - ans;

    cout << setprecision(9) << fixed << ans << endl;
}
