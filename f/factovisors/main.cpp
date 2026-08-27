#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll mxN = 46500;

vll p;
ll spf[mxN];

void sieve() {
    for (ll i = 2; i < mxN; ++i) if (!spf[i]) {
        spf[i] = i;
        p.push_back(i);
        for (ll j = i * i; j < mxN; j += i) if (!spf[j]) spf[j] = i;
    }
}

int main() {
    sieve();

    ll n, m;
    while (scanf("%lld%lld", &n, &m) != EOF) {
        if (m == 0) {
            printf("%lld does not divide %lld!\n", m, n);
            continue;
        }
        map<ll, int> cnt;
        ll mo = m;

        for (int i = 0; i < p.size() && p[i] * p[i] <= m; ++i) {
            while (m % p[i] == 0) {
                ++cnt[p[i]];
                m /= p[i];
            }
        }
        if (m != 1)++cnt[m];

        bool fail = 0;
        for (auto [k, v] : cnt) {
            ll sn = 0;

            ll pv = k;
            for (int i = 1; n / pv; ++i) {
                sn += n / pv;
                pv *= k;
            }

            if (sn < v) {
                fail = 1;
                break;
            }
        }

        if (fail) {
            printf("%lld does not divide %lld!\n", mo, n);
        } else {
            printf("%lld divides %lld!\n", mo, n);
        }
    }
}
