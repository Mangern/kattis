#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct point {
    ll x;
    ll y;
};

const int mxN = 105;

point loc[mxN];
ll r[mxN];

ll d2(point p1, point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int main() {
    ll w, h;
    cin >> w >> h;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> loc[i].x >> loc[i].y >> r[i];
    }

    for (int i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;

        bool good = 1;
        for (int j = 0; j < n; ++j) {
            // is asteroid inside?
            if (x <= loc[j].x && loc[j].x <= x + w && y <= loc[j].y && loc[j].y <= y + h) {
                good = 0;
                break;
            }
            if (x <= loc[j].x && loc[j].x <= x + w) {
                ll v = min(abs(y - loc[j].y), abs(y + h - loc[j].y));
                if (v <= r[j]) {
                    good = 0;
                    break;
                }
                continue;
            }
            if (y <= loc[j].y && loc[j].y <= y + h) {
                ll h = min(abs(x - loc[j].x), abs(x + w - loc[j].x));
                if (h <= r[j]) {
                    good = 0;
                    break;
                }
                continue;
            }

            ll d = min(
                min(d2(point{x,y}, loc[j]), d2(point{x+w,y}, loc[j])),
                min(d2(point{x,y+h}, loc[j]), d2(point{x+w,y+h}, loc[j]))
            );

            // corner
            if (d <= r[j] * r[j]) {
                good = 0;
                break;
            }
        }

        cout << "DOOMSLUG " << (good ? "GO!" : "STOP!") << endl;
    }
}
