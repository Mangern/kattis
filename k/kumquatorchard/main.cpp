#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll, ll>;

int main() {
    ll n;
    cin >> n;

    vector<ii> l1, l2, l3, l4;
    vector<ii> q1, q2, q3, q4;

    for (int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;

        ii p = {x, y};
        if (x == 0) {
            if (y > 0) {
                l2.push_back(p);
            } else {
                l4.push_back(p);
            }
        } else if (y == 0) {
            if (x > 0) {
                l1.push_back(p);
            } else {
                l3.push_back(p);
            }
        } else {
            if (x > 0 && y > 0) {
                q1.push_back(p);
            } else if (x < 0 && y > 0) {
                q2.push_back(p);
            } else if (x < 0 && y < 0) {
                q3.push_back(p);
            } else {
                q4.push_back(p);
            }
        }
    }
    constexpr int N = 8;
    
    vector<vector<ii>> groups = {l1, q1, l2, q2, l3, q3, l4, q4};
    vector<ii> repr = {{1,0}, {1,1}, {0,1},{-1,1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
    vector<bool> has_pts(8,false);
    for (int i = 0; i< N; ++i) {
        has_pts[i] = !groups[i].empty();
    }

    auto is_valid = [&] (int mask) {
        if (mask == 0) return true;
        ll minx = 100, maxx = -100, miny = 100, maxy = -100;
        bool has_pt = false;
        for (int i = 0; i < N; ++i) {
            if ((mask >> i) & 1) {
                auto [x, y] = repr[i];
                minx = min(minx, x);
                maxx = max(maxx, x);
                miny = min(miny, y);
                maxy = max(maxy, y);

                if (has_pts[i])has_pt = true;
            }
        }
        if (!has_pt) return false;
        if (minx <= 0 && maxx >= 0 && miny <= 0 && maxy >= 0) return false;
        return true;
    };

    int ans = 5;
    array<int, 4> ans_masks;
    for (int m1 = 0; m1 < (1<<N); ++m1) {
        if (!is_valid(m1)) continue;
        for (int m2 = 0; m2 < (1<<N); ++m2) {
            if (m2 & m1) continue;
            if (!is_valid(m2)) continue;
            for (int m3 = 0; m3 < (1<<N); ++m3) {
                if (m3 & m2) continue;
                if (m3 & m1) continue;
                if (!is_valid(m3)) continue;
                for (int m4 = 0; m4 < (1<<N); ++m4) {
                    if (m4 & m3)continue;
                    if (m4 & m2)continue;
                    if (m4 & m1)continue;
                    if (!is_valid(m4)) continue;

                    int cover = m1 | m2 | m3 | m4;

                    bool ok=1;
                    for (int i = 0; i < N; ++i) {
                        if ((cover >> i) & 1) continue;
                        if (has_pts[i]) {
                            ok=0;
                            break;
                        }
                    }
                    if (!ok) continue;

                    int cur = 0;
                    if (m1)++cur;
                    if (m2)++cur;
                    if (m3)++cur;
                    if (m4)++cur;

                    if (cur < ans) {
                        ans = cur;
                        ans_masks = {m1, m2, m3, m4};
                    }
                }
            }
        }
    }

    vector<vector<pair<double,double>>> rects;
    for (int i = 0; i < 4; ++i) {
        if (!ans_masks[i]) continue;
        ll minx = 10000, maxx = -10000, miny = 10000, maxy = -10000;
        for (int j = 0; j < N; ++j) {
            if ((ans_masks[i] >> j) & 1) {
                for (auto [x, y] : groups[j]) {
                    minx = min(minx, x);
                    maxx = max(maxx, x);
                    miny = min(miny, y);
                    maxy = max(maxy, y);
                }
            }
        }

        vector<pair<double,double>> rect;
        rect.emplace_back((double)minx-0.2, (double)miny-0.2);
        rect.emplace_back((double)minx-0.2, (double)maxy+0.2);
        rect.emplace_back((double)maxx+0.2, (double)maxy+0.2);
        rect.emplace_back((double)maxx+0.2, (double)miny-0.2);
        rects.push_back(rect);
    }

    cout << rects.size() << endl;

    for (auto &rect : rects) {
        for (auto [x, y] : rect) {
            cout << setprecision(1) << fixed << x << ' ';
            cout << setprecision(1) << fixed << y << ' ';
        }
        cout << endl;
    }
}
