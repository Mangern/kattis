#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

const int mxN = 55;

int n;
ii pts[mxN];
int idx[mxN];

// p1 -> p2 -> p3: Angle at p2 for sorting
double angle(const ii& p1, const ii& p2, const ii& p3) {
    int ux = p2.first - p1.first;
    int uy = p2.second - p1.second;
    int vx = p3.first - p2.first;
    int vy = p3.second - p2.second;

    int cross = ux * vy - uy * vx;
    int dot = ux * vx + uy * vy;

    int sign = cross > 0 ? 1 : -1;

    return sign * acos((double)dot / (double)(hypot(ux, uy) * hypot(vx, vy)));
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> pts[i].first >> pts[i].second;
    }
    string s;
    cin >> s;
    iota(idx, idx + n, 0);
    sort(idx, idx + n, [&](auto i, auto j) {
        if (pts[i].second == pts[j].second) {
            return pts[i].first < pts[j].first;
        }
        return pts[i].second < pts[j].second;
    });


    auto sort_suffix = [&] (int start, ii p1, ii p2) {
        sort(idx + start, idx + n, [&](auto i, auto j) {
            double a1 = angle(p1, p2, pts[i]);
            double a2 = angle(p1, p2, pts[j]);
            return a1 < a2;
        });
    };

    ii tmp{pts[idx[0]].first - 1, pts[idx[0]].second};
    sort_suffix(1, tmp, pts[idx[0]]);

    if (s[0] == 'R') {
        swap(idx[1], idx[n-1]);
    }

    for (int i = 0; i + 1 < s.length(); ++i) {
        ii p1 = pts[idx[i]];
        ii p2 = pts[idx[i+1]];
        sort_suffix(i + 2, p1, p2);

        if (s[i] == 'L' && s[i+1] == 'L') {
            int found_idx = -1;
            for (int j = i + 2; j < n; ++j) {
                if (angle(p1, p2, pts[idx[j]]) > 0) {
                    found_idx = j;
                    break;
                }
            }
            assert(found_idx != -1);
            swap(idx[i + 2], idx[found_idx]);
        } else if (s[i] == 'L' && s[i+1] == 'R') {
            swap(idx[i + 2], idx[n - 1]);
        } else if (s[i] == 'R' && s[i+1] == 'L') {
        } else {
            int found_idx = -1;
            for (int j = i + 2; j < n; ++j) {
                if (angle(p1, p2, pts[idx[j]]) < 0) {
                    found_idx = j;
                }
            }
            assert(found_idx != -1);
            swap(idx[i + 2], idx[found_idx]);
        }
    }

    for (int i = 0; i < n; ++i)cout << idx[i] + 1 << ' ';
    cout << endl;
}
