#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 46500;

vector<ll> p;
ll spf[mxN];

map<ll, int> factorize(ll m) {
    map<ll, int> cnt;

    for (int i = 0; i < p.size() && p[i] * p[i] <= m; ++i) {
        while (m % p[i] == 0) {
            ++cnt[p[i]];
            m /= p[i];
        }
    }
    if (m > 1)++cnt[m];
    return cnt;
}

ll pw(ll a, ll b) {
    if (b == 0) return 1;
    ll r = pw(a, b >> 1);
    r = r * r;
    if (b & 1) r = r * a;
    return r;
}

void sieve() {
    for (ll i = 2; i < mxN; ++i) if (!spf[i]) {
        spf[i] = i;
        p.push_back(i);
        for (ll j = i * i; j < mxN; j += i) if (!spf[j]) spf[j] = i;
    }
}

int main() {
    sieve();

    ll n;
    while (cin >> n) {
        auto f = factorize(n);
        ll ans = 1;
        for (auto [k, v] : f) ans *= pw(v, k);
        cout << n << " " << ans << endl;
    }
}
