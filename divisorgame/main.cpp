#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 1e6+6;
const int mxM = 1e5+5;
const ll MOD = 1e9+7;

vector<ll> primes;
ll fac[mxN];
ll ifac[mxN];
bool isp[mxN];
ll spf[mxN];

ll nck(ll n, ll k) {
    ll ret = fac[n];
    ret = ret * ifac[k] % MOD;
    ret = ret * ifac[n-k] % MOD;
    return ret;
}

ll mpow(ll a, ll b) {
    if (b == 0) return 1;
    ll r = mpow(a, b >> 1);
    r = (r * r) % MOD;
    if (b & 1) r = (r * a) % MOD;
    return r;
}

void solve() {
    ll a, b;
    cin >> a >> b;
    ll n = b - a + 1;
    vector<vector<ll>> pf(n);
    for (ll i : primes) {
        if (i * i > b) break;
        // i * x >= a
        // x >= a / i
        for (ll x = (a + i - 1) / i; i * x <= b; ++x) {
            if (x == 1) continue;
            pf[i * x - a].push_back(i);
        }
    }

    vector<ll> np(n, 0);

    ll num_primes = 0;

    for (ll i = 0; i < n; ++i) {
        if (pf[i].empty()) {
            np[i] = 1;
            ++num_primes;
            continue;
        }

        ll val = i + a;
        // how many prime factors does val have?
        for (ll p : pf[i]) {
            while (val % p == 0) {
                ++np[i];
                val /= p;
            }
        }
        while (1 < val && val < mxN) {
            ++np[i];
            val /= spf[val];
        }
        if (val >= mxN) ++np[i]; // it is a prime ? I think.
    }

    ll D = 40;
    vector<ll> basis(D, 0);
    ll nwaste=0;

    auto ins = [&] (ll mask) {
        for (ll i = D - 1; i >= 0; --i) {
            if (!((mask >> i) & 1)) continue;
            if (!basis[i]) {
                basis[i] = mask;
                return;
            }
            mask ^= basis[i];
        }
        ++nwaste;
    };
    for (ll i = a; i <= b; ++i) {
        ins(np[i-a]);
    }
    // 2**nwaste - 1 ways to chose a non-empty xor sum of zero (where player 2 wins)
    ll p2 = 1;
    for (ll i = 0; i < nwaste; ++i) {
        p2 = (p2 << 1) % MOD;
    }
    ll ans = (p2 + MOD - 1) % MOD;

    // then, we need to add the number of ways to choose an odd number of primes,
    // and subtract the number of ways to choose an even number of primes

    for (ll i = 1; i <= num_primes; ++i) {
        ll val = nck(num_primes, i);
        if (i & 1) ans = (ans + val) % MOD;
        else ans = ((ans - val) % MOD + MOD) % MOD;
    }
    cout << ans << endl;
}

void pre() {
    memset(isp, 1, sizeof isp);

    for (ll i = 2; i < mxN; ++i) {
        if (!isp[i]) continue;
        primes.push_back(i);
        spf[i] = i;

        for (ll j = i * i; j < mxN; j += i) {
            isp[j] = 0;
            if (!spf[j]) {
                spf[j] = i;
            }
        }
    }

    fac[0] = 1;
    for (ll i = 1; i < mxM; ++i) {
        fac[i] = i * fac[i-1] % MOD;
    }
    ifac[mxM-1] = mpow(fac[mxM-1], MOD - 2);

    for (ll i = mxM - 1; i > 0; --i) {
        ifac[i-1] = ifac[i] * i % MOD;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    pre();
    int t;
    cin >> t;
    while (t-->0) {
        solve();
    }
}
