#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll,2>;

int main() {
    int n;
    cin >> n;
    vector<ii> pts(n);
    for (auto &[x,y] : pts)cin >> x >> y;
    set<ii> have(begin(pts),end(pts));

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) if (pts[j][0] > pts[i][0] && pts[j][1] >= pts[i][1]) {
            ll dx = pts[j][0] - pts[i][0];
            ll dy = pts[j][1] - pts[i][1];

            ll rx = -dy;
            ll ry = dx;

            ii need1 = {pts[i][0] + rx, pts[i][1] + ry};
            ii need2 = {pts[j][0] + rx, pts[j][1] + ry};

            if (have.count(need1) && have.count(need2))++ans;
        }
    }
    cout << ans << endl;
}
