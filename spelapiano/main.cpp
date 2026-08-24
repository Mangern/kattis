#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, m;
    cin >> n >> m;

    ll lo = 1;
    ll hi = 1;
    ll cur = 1;

    for (ll i = 0; i < m - 1; ++i) {
        ll t;
        cin >> t;

        cur += t;
        lo = min(lo, cur);
        hi = max(hi, cur);
    }

    // lo + x == 1
    // start = 1 + x
    ll x = 1 - lo;
    if (hi + x > n) {
        cout << "finns ingen" << endl;
    } else {
        cout << 1 + x << endl;
    }
}
