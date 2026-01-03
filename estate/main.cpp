#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    for (;;) {
        ll n;
        cin >> n;
        if (!n) break;

        auto check = [] (ll x, ll n) {
            ll k2 = (2 * n) / x - (x - 1);
            if (k2 < 4) return 0LL;
            if (k2 % 2 != 0) return 0LL;
            return k2/2;
        };

        set<ll> works;
        for (ll x = 1; x * x <= 2 * n; ++x) {
            if ((2 * n) % x == 0) {
                ll k = check(x, n);
                if (k)works.insert(k);
                k = check(2*n/x, n);
                if (k)works.insert(k);
            }
        }
        cout << works.size() << endl;
    }
}
