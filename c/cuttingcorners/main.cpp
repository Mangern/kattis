#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll,2>;

pair<ll,double> sharp(const vector<ii>& poly) {
    int n = poly.size();

    double mn = 1000;
    int mni=0;
    for (int i = 0; i < n; ++i) {
        int nxt = (i + 1) % n;
        int prv = (i - 1 + n) % n;

        ll xnxt = poly[nxt][0] - poly[i][0];
        ll ynxt = poly[nxt][1] - poly[i][1];
        ll xprv = poly[prv][0] - poly[i][0];
        ll yprv = poly[prv][1] - poly[i][1];

        double cosa = (double)(xnxt * xprv + ynxt * yprv) / (double)(hypot(xnxt,ynxt)*hypot(xprv,yprv));
        double a = acos(cosa);
        if (a<mn) {
            mn=a;
            mni = i;
        }
    }
    return {mni, mn};
}

int main() {
    for (;;) {
        int n;
        cin >> n;
        if (!n) break;

        vector<ii> poly;
        for (int i = 0; i < n; ++i) {
            ll x, y;
            cin >> x >> y;
            poly.push_back({x,y});
        }

        while (poly.size() > 3) {
            auto [mni, mna] = sharp(poly);
            vector<ii> npoly;
            for (int i = 0; i < poly.size(); ++i) {
                if (i != mni)npoly.push_back(poly[i]);
            }
            auto [nmni, nmna] = sharp(npoly);
            if (nmna < mna) break;
            poly = npoly;
        }

        cout << poly.size();

        for (auto [x, y] : poly) cout << " " << x << " " << y;
        cout << endl;
    }
}
