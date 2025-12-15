#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll, 2>;

int main() {
    ll n, ys, yt;
    ll tmp;

    cin >> n >> tmp >> ys >> tmp >> yt;


    vector<ii> seg(n);

    for (int i = 0; i < n; ++i) {
        ll yl, yr;
        cin >> tmp >> yl >> tmp >> yr;
        seg[i] = {yl, yr};
    }

    if (yt >= ys) {
        cout << 0 << endl;
        return 0;
    }

    sort(begin(seg), end(seg));

    ll yptr = yt;
    ll ans = 0;
    for (auto [l, r] : seg) {
        ans += max(0LL, min(l, ys) - yptr);
        yptr = max(yptr, r);
        yptr = min(yptr, ys);
    }
    ans += ys - yptr;
    cout << ans << endl;
}
