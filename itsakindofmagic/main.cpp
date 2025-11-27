#include <bits/stdc++.h>
using namespace std;
using ll = long long;


const ll mxN = 1e6+1;

ll spf[mxN];
vector<ll> primes;
ll sm[65];
ll cnt[mxN];

int main() {

    for (ll i = 2; i < mxN; ++i) {
        if (spf[i]) continue;
        spf[i] = i;
        for (ll j = i * i ; j < mxN; j += i) {
            if (!spf[j])spf[j] = i;
        }
    }

    for (ll m = 1; m < mxN; ++m) {
        ll x = m;
        ll c1,c2,c3,c4,c5;
        c1 = c2 = c3 = c4 = c5 = 1;
        while (x > 1) {
            ll p = spf[x];
            ll e = 0;
            while (x % p == 0) {
                x /= p;
                ++e;
            }
            c1 *= 2 * e * e + 2 * e + 1;
            c2 *= 2 * (e / 3) + 1;
            c3 *= 2 * (e / 2) + 1;
            c4 *= 2 * e + 1;
        }
        cnt[m] = c1 - 4 * c2 - 2 * c3 - 2 * c4 + 7 * c5;
        cnt[m] += cnt[m-1];
    }

    ll t;
    cin >> t;
    while (t-->0) {
        ll n;
        cin >> n;

        ll c = cbrt(n);
        while ((c+1)*(c+1)*(c+1) <= n)++c;
        while (c*c*c>n)--c;

        cout << cnt[c] << endl;
    }
}
