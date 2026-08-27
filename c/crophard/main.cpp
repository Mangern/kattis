#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; ++tt) {
        ll n, a,b,c,d, x0, y0, m;
        cin >> n >> a >> b >> c >> d >> x0 >> y0 >> m;
        vector<pair<ll,ll>> pts;
        pts.push_back({x0,y0});

        for (int i = 0; i < n - 1; ++i) {
            x0 = (a * x0 % m + b) % m;
            y0 = (c * y0 % m + d) % m;
            pts.push_back({x0, y0});
        }

        map<pair<ll,ll>, ll> cnt;

        for (auto [x, y] : pts) {
            cnt[{x%3, y%3}]++;
        }

        ll ans = 0;
        for (auto [p1, c1] : cnt) {
            auto [x1, y1] = p1;
            for (auto [p2, c2] : cnt) if (p2 >= p1) {
                auto [x2, y2] = p2;
                for (auto [p3, c3] : cnt) if (p3 >= p2) {
                    auto [x3, y3] = p3;
                    if ((x1 + x2 + x3) % 3 == 0 && (y1 + y2 + y3) % 3 == 0) {
                        if (p1 == p3) {
                            // c1 choose 3
                            ans += (c1 * (c1 - 1) / 2) * (c1 - 2) / 3;
                        } else if (p1 == p2) {
                            // c1 choose 2 * c3
                            ans += (c1 * (c1 - 1)) / 2 * c3;
                        } else if (p2 == p3) {
                            ans += c1 * (c2 * (c2 - 1) / 2);
                        } else {
                            ans += c1 * c2 * c3;
                        }
                    }
                }
            }
        }

        cout << "Case #" << tt << ": " << ans << endl;
    }
}
