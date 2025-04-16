#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 1e6+6;

ll n, k;
ll cnt[mxN];
ll pref[mxN];

int main() {
    scanf("%lld%lld", &n, &k);

    for (ll i = 0; i < k; ++i) {
        ll x;
        scanf("%lld", &x);
        ++cnt[x];
    }

    for (ll x = 0; x < n; ++x) if (cnt[x] > 0) {
        for (ll dx = 0; dx < n; dx += x) {
            pref[dx] += cnt[x];
        }
    }

    for (ll i = 1; i < n; ++i) {
        pref[i] += pref[i-1];
    }

    ll q;
    scanf("%lld",&q);

    while (q-->0) {
        ll l, r;
        scanf("%lld%lld",&l,&r);

        printf("%lld\n", pref[r] - (l == 0 ? 0LL : pref[l-1]));
    }
}
