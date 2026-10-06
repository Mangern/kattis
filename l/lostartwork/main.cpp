#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T-->0) {
        int n;
        cin >> n;
        vector<pair<double, double>> pts(n);
        for (auto &[x, y] : pts) cin >> x >> y;

        sort(begin(pts), end(pts));

        double mxy = 0.0;
        double ans = 0.0;
        for (int i = n - 1; i > 0; --i) {
            auto [x, y] = pts[i];
            auto [xp, yp] = pts[i-1];
            double l = hypot(x - xp, y - yp);
            if (yp > y && yp > mxy) {
                if (y >= mxy) {
                    ans += l;
                } else {
                    ans += l * (yp - mxy) / (yp - y);
                }
            }

            mxy = max(mxy, yp);
        }
        cout << setprecision(2) << fixed << ans << endl;
    }
}
