#include <bits/stdc++.h>
using namespace std;
using ll =long long;

const int mxN = 66000;

ll spf[mxN];
vector<ll> primes;

int main() {
    for (ll i = 2; i < mxN; ++i) {
        if (spf[i]) continue;
        spf[i] = i;
        primes.push_back(i);

        for (ll j = i * i; j < mxN; j += i) {
            if (!spf[j])spf[j] = i;
        }
    }

    for (;;) {
        ll x;
        cin >> x;
        if (!x) break;

        bool o = x < 0;
        x = abs(x);

        if (x == 1) {
            cout << 1 << endl;
            continue;
        }

        map<ll, ll> cnt;

        for (auto p : primes) {
            while (x % p == 0) {
                ++cnt[p];
                x /= p;
            }
        }

        if (x > 1) {
            cout << 1 << endl;
            continue;
        }
        ll g = 0;

        for (auto [k, v] : cnt) {
            if (g == 0) g = v;
            else g = gcd(g, v);
        }
        if (!g) g = 1;

        if (o) {
            ll bg;
            for (ll i = 1; i <= g; i += 2) {
                if (g % i == 0)bg =i ;
            }
            g = bg;
        }
        cout << g << endl;
    }
}
