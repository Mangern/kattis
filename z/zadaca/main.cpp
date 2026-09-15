#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 1e5+5;

vector<ll> primes;
ll spf[mxN];

int main() {
    for (ll p = 2; p < mxN; ++p) {
        if (spf[p]) continue;
        primes.push_back(p);
        spf[p] = p;

        for (ll i = p * p; i < mxN; i += p) {
            if (!spf[i])spf[i] = p;
        }
    }

    unordered_map<ll, ll> pA, pB;

    auto process = [&](ll x, unordered_map<ll, ll>& mp) {
        if (x >= mxN) {
            for (auto p : primes) {
                if (p > x) break;
                while (x % p == 0) {
                    ++mp[p];
                    x /= p;
                }
            }
        }
        if (x < mxN) {
            while (x > 1) {
                ll p = spf[x];
                ++mp[p];
                x /= p;
            }
        }

        if (x > 1) {
            ++mp[x];
        }
    };

    ll n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;

        process(x, pA);
    }

    ll m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        ll x;
        cin >> x;

        process(x, pB);
    }

    ll lim = 1000000000;
    ll ans = 1;
    bool hit = 0;

    for (auto [p, cnt] : pA) {
        cnt = min(cnt, pB[p]);
        for (int i = 0; i < cnt; ++i) {
            ans *= p;
            if (hit || ans > lim) {
                ans %= lim;
                hit = 1;
            }
        }
    }

    if (hit) {
        printf("%09lld\n", ans);
    } else {
        printf("%lld\n", ans);
    }
}
