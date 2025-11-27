#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll,2>;

#define all(v) begin(v), end(v)

const int mxN = 1005;

void uniq(vector<ii> &pts) {
    sort(all(pts));
    pts.erase(unique(all(pts)),end(pts));
}

int main() {
    int n;
    vector<ii> pts(5);
    n = 5;
    for (auto &[x, y] : pts) {
        cin >> x >> y;
    }

    auto lcmp = [](const ii &a, const ii &b) {
        if (a[0] == b[0])return a[1]<b[1];
        return a[0]<b[0];
    };
    auto rcmp = [](const ii &a, const ii &b) {
        if (a[0] == b[0])return a[1]<b[1];
        return a[0]>b[0];
    };
    auto tcmp = [](const ii &a, const ii &b) {
        if (a[1] == b[1])return a[0]<b[0];
        return a[1]>b[1];
    };
    auto bcmp = [](const ii &a, const ii &b) {
        if (a[1] == b[1])return a[0]<b[0];
        return a[1]<b[1];
    };

    ll ans = 0;
    while (pts.size()>1) {
        sort(all(pts), lcmp);

        if (pts[0][0] != pts[1][0]) {
            ans += pts[1][0] - pts[0][0];
            ii np = {pts[1][0],pts[0][1]};
            pts[0] = np;
            uniq(pts);
            continue;
        }

        sort(all(pts), rcmp);

        if (pts[0][0] != pts[1][0]) {
            ans += pts[0][0] - pts[1][0];
            ii np = {pts[1][0], pts[0][1]};
            pts[0] = np;
            uniq(pts);
            continue;
        }

        sort(all(pts), tcmp);
        if (pts[0][1] != pts[1][1]) {
            ans += pts[0][1] - pts[1][1];
            ii np = {pts[0][0], pts[1][1]};
            pts[0] = np;
            uniq(pts);
            continue;
        }

        sort(all(pts), bcmp);
        if (pts[0][1] != pts[1][1]) {
            ans += pts[1][1] - pts[0][1];
            ii np = {pts[0][0], pts[1][1]};
            pts[0] = np;
            uniq(pts);
            continue;
        }

        break;
    }

    if (pts.size()>1) {
        set<ll> xs;
        set<ll> ys;
        for (auto [x, y] : pts) {
            xs.insert(x);
            ys.insert(y);
        }
        ll xl = *xs.begin();
        ll xh = *--xs.end();
        ll yl = *ys.begin();
        ll yh = *--ys.end();
        ans += 2 * (xh - xl) + 2 * (yh - yl);

        for (auto [x, y] : pts) {
            if (x != xl && x != xh && y != yl && y != yh) {
                ans += min(xh-xl, yh-yl);
            }
        }
    }
    cout << ans << endl;
}
