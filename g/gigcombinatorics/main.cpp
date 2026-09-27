#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9+7;


ll mpow(ll a, ll b) {
    if (b == 0) return 1;
    ll r = mpow(a, b >> 1);
    r = (r * r) % MOD;
    if (b & 1) r = (r * a) % MOD;
    return r;
}

int main() {
    ll n;
    cin >> n;

    ll ans = 0;

    vector<ll> a(n);
    for (auto &x : a) {
        cin >> x;
    }

    ll S = 0;

    ll i2 = mpow(2, MOD - 2);

    ll n2 = 0, n3 = 0;
    for (ll i = 0; i < n; ++i) {
        if (a[i] == 2) {
            ++n2;
        }
        if (a[i] == 3) {
            ++n3;

            S += mpow(2, n2);
            S %= MOD;
            S += MOD - 1;
            S %= MOD;
        }
    }

    for (ll i = 0; i < n; ++i) {
        if (a[i] == 1) {
            ans += S;
            ans %= MOD;
        }
        if (a[i] == 2) {
            S += n3;
            S %= MOD;
            S *= i2;
            S %= MOD;
            S -= n3;
            S %= MOD;
            S += MOD;
            S %= MOD;
        }
        if (a[i] == 3) {
            --n3;
        }
    }

    cout << ans << endl;
}
