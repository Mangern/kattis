#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<array<ll, 3>> a;
    ll mxh = 0;
    for (int i = 0; i < n; ++i) {
        ll h, r, t;
        cin >> h >> r >> t;
        a.push_back({h,r,t});
        mxh = max(mxh, h);
    }

    for (ll d = 0; d < 1825; ++d) {
        for (ll h = 0; h < mxh; ++h) {
            bool ok=1;
            for (auto [len, r, t] : a) {
                ll h_here = (d*mxh+h) % len;

                if (r<t) {
                    if (r < h_here && h_here < t) {
                        ok = 0;
                    }
                } else {
                    if (r < h_here || h_here < t) {
                        ok = 0;
                    }
                }
            }
            if (ok) {
                cout << d * mxh + h << endl;
                return 0;
            }
        }
    }
    cout << "impossible" << endl;
}
