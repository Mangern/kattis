#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 432;

int spf[mxN];

void pre() {
    for (int i = 2; i < mxN; ++i) if (!spf[i]) {
        spf[i] = i;
        for (int j = i * i; j < mxN; j += i) if (!spf[j])spf[j] = i;
    }
}

int main() {
    pre();
    ll n, k;
    while (cin >> n) {
        cin >> k;

        // n!/(k!(n-k)!)
        map<ll, ll> ps;

        for (ll i = 1; i <= n; ++i) {
            ll x = i;
            while (x > 1) {
                ++ps[spf[x]];
                x /= spf[x];
            }
        }

        for (ll i = 1; i <= k; ++i) {
            ll x = i;
            while (x > 1) {
                --ps[spf[x]];
                x /= spf[x];
            }
        }

        for (ll i = 1; i <= n-k; ++i) {
            ll x = i;
            while (x > 1) {
                --ps[spf[x]];
                x /= spf[x];
            }
        }
        ll ans = 1;
        for (auto [k, v] : ps) {
            ans *= (v + 1);
        }
        cout << ans << endl;
    }
    return 0;
}
