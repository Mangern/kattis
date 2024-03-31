#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using tup = array<ll,3>;

const ll MOD = 1e9+7;
ll mpow(ll a, ll b) {
    if (b == 0)return 1;
    ll r = mpow(a, b / 2);
    r = (r * r) % MOD;
    if (b % 2 == 1)r = (r * a)%MOD;
    return r;
}
const int mxN = 800004;

ll n;

ll fac[mxN];
ll ifac[mxN];
ll p2[mxN];

ll solve(ll c, ll m, ll k) {
    if (k == 0) {
        return (c+m == 0 ? 1 : 0);
    }
    ll ans = 0;
    for (ll t1 = 0; t1 <= c; ++t1) {
        ll t2 = m - c + t1;
        ll t3 = k - t1 - t2;

        if (t2 < 0)continue;
        if (t3 < 0)continue;
        if (c - t1 - t3 < 0)continue;

        ll res = fac[k];

        res = (res * ifac[t1]) % MOD;
        res = (res * ifac[t2]) % MOD;
        res = (res * ifac[t3]) % MOD;

        res = (res * fac[c+t2-1]) % MOD;
        res = (res * ifac[c-t1-t3]) % MOD;
        res = (res * ifac[k-1]) % MOD;
        res = (res * p2[t3]) % MOD;

        ans = (ans + res) % MOD;

    }
    return ans;
}

int main() {
    fac[0] = 1;
    p2[0] = 1;
    for (ll i = 1; i < mxN; ++i) {
        p2[i] = (2 * p2[i-1]) % MOD;
        fac[i] = (i * fac[i-1]) % MOD;
    }
    ifac[mxN-1] = mpow(fac[mxN-1], MOD-2);
    for (ll i = mxN - 1; i > 0; --i) {
        ifac[i-1] = (i * ifac[i]) % MOD;
    }
    ll a, c, m;
    cin >> a >> c >> m;
    n = a+c+m;

    if (a < c)swap(a,c);
    if (a < m)swap(a,m);
    if (c < m)swap(c,m);

    ll ans = solve(c,m, a-1) + 2 * solve(c, m, a) + solve(c, m, a+1);

    cout << ans % MOD << endl;

    return 0;
}
