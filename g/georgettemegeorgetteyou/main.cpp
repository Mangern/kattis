#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mxN = 1e6+6;

ll m;
ll a[mxN];
ll fac[mxN];

int main() {
    ll t;
    scanf("%lld %lld", &t, &m);

    fac[1] = 1;
    a[0] = 1;
    a[1] = 1;

    for (ll i = 2; i < mxN; ++i) {
        fac[i] = fac[i-1] * i % m;

        a[i] = (a[i-1] + (i - 1) * a[i-2] % m) % m;
    }

    while (t-->0) {
        ll x;
        scanf("%lld", &x);

        printf("%lld\n", ((fac[x] - a[x]) % m + m) % m);
    }
}
