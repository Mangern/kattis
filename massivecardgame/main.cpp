#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define all(v) begin(v), end(v)

int main() {
    ll n;
    cin >> n;

    vector<ll> a(n);
    for (auto &x:a)cin >> x;

    sort(all(a));

    ll q;
    cin >> q;

    while (q-->0) {
        ll l, r;
        cin >> l >> r;

        auto lo = lower_bound(all(a), l);
        auto hi = upper_bound(all(a), r);

        cout << hi - lo << endl;
    }
}
