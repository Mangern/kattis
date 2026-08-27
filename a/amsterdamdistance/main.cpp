#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    double m, n, r;
    cin >> m >> n >> r;

    double alpha = M_PI / m;
    double d = r / n;

    ll ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;

    double delta_alpha = abs(ax-bx) * alpha;

    double ans = numeric_limits<double>::infinity();
    for (ll i = 0; i <= n; ++i) {
        double rad = d * i;

        double cur = abs(ay - i) * d + rad * delta_alpha + abs(by - i) * d;
        ans = min(ans, cur);
    }
    cout << setprecision(12) << fixed << ans << endl;
}
