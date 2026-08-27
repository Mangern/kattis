#include <bits/stdc++.h>
using namespace std;

struct point {
    double x;
    double y;
};

int main() {
    int n;
    cin >> n;
    vector<point> pts(n);
    for (auto &p : pts) cin >> p.x >> p.y;

    double ans = numeric_limits<double>::infinity();

    for (int i = 0; i < n; ++i) {
        double sum = 0.0;
        for (int j = 0; j < n; ++j) {
            sum += hypot(pts[i].x - pts[j].x, pts[i].y - pts[j].y);
        }
        ans = min(ans, sum);
    }
    ans /= (n - 1);
    cout << setprecision(10) << fixed << ans << endl;
}
