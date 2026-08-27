#include <iostream>
#include <cassert>

using namespace std;
using ll = long long;

ll modpow(ll a, ll b, ll m) {
    a %= m;
    if (b == 0)return 1;
    if (b == 1)return a;

    ll r = modpow(a, b / 2, m);

    r = (r * r) % m;

    if (b % 2 == 1) {
        r = (r * a) % m;
    }
    return r;
}

ll geom(ll a, ll n, ll m) {
    // return 1 + a + ... + a^n % m

    if (n == 0)return 1;
    if (n == 1)return (1 + a) % m;

    if (n % 2 == 0) {
        return geom(a, n - 1, m) + modpow(a, n, m);
    }

    ll k = (n - 1) / 2;
    // (1 + a^(k+1)) * (1 + a + ... + a^k)

    ll res = geom(a, k, m);

    res = res * ((1 + modpow(a, k+1, m)) % m) % m;
    return res;
}

int main() {
    ll a, b, x, n, m;
    cin >> a >> b >> x >> n >> m;

    if (a <= 1) {
        ll res = (((n % m) * b)%m + x * a)%m;
        cout << res << endl;
        return 0;
    }

    ll x_coeff = modpow(a, n, m);

    ll b_coeff = geom(a, n-1, m);

    ll res = (x_coeff * x) % m;
    res = (res + (b_coeff * b) % m) % m;
    cout << res << endl;
}
