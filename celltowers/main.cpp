#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll, 2>;
using tup = array<ll, 3>;

int main() {
    for (;;) {
        ll t, r;
        cin >> t;
        if (!t) break;
        cin >> r;

        vector<tup> towers;
        for (int i = 0; i < t; ++i) {
            ll x, y, p;
            cin >> x >> y >> p;
            towers.push_back({x, y, p});
        }

        vector<ii> road;

        for (ll i = 0; i <= r; ++i) {
            ll x, y;
            cin >> x >> y;
            road.push_back({x, y});
        }

        auto strength = [&] (int tw, double x, double y) {
            auto [tx, ty, p] = towers[tw];
            double d2 = (tx - x) * (tx - x) + (ty - y) * (ty - y);
            return (ll)round(p / d2);
        };

        auto find_tower = [&] (double x, double y) {
            int best = 0;
            ll strength_to_best = strength(0, x, y);
            for (int i = 1; i < towers.size(); ++i) {
                ll strength_here = strength(i, x, y);
                if (strength_here > strength_to_best) {
                    best = i;
                    strength_to_best = strength_here;
                }
            }
            return best;
        };

        vector<pair<double, double>> pois;

        double rem = 0.0;

        double dx, dy;
        for (int i = 0; i < r; ++i) {
            dx = road[i+1][0] - road[i][0];
            dy = road[i+1][1] - road[i][1];

            double h = hypot(dx, dy);
            dx /= h;
            dy /= h;

            if (rem > h) {
                rem -= h;
                continue;
            }
            double cx = road[i][0];
            double cy = road[i][1];
            double acc = 0.0;
            cx += dx * rem;
            cy += dy * rem;
            acc += rem;
            pois.push_back({cx, cy});

            while (acc + 1.0 <= h) {
                cx += dx;
                cy += dy;
                acc += 1.0;
                pois.push_back({cx, cy});
            }
            rem = acc + 1.0 - h;
        }

        if (rem < 0.5) {
            pois.push_back({double(road.back()[0]), double(road.back()[1])});
        }

        vector<pair<int, char>> ans;

        for (int i = 0; i < pois.size(); ++i) {
            auto [x, y] = pois[i];
            char tw = 'A' + find_tower(x, y);
            // cout << i << " " << tw << endl;
            if (ans.empty() || ans.back().second != tw) {
                ans.push_back({i, tw});
            }
        }

        for (int i = 0; i < ans.size(); ++i) {
            cout << '(' << ans[i].first << ',' << ans[i].second << ')' << " \n"[i+1==ans.size()];
        }
    }
}
