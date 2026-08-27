#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 100000;

bool isp[N];
vector<ll> primes;

ll phi(ll n) {
    ll ans = n;

    for (ll i = 0; i < primes.size() && primes[i] * primes[i] <= n; ++i) {
        if (n % primes[i] == 0) ans -= ans / primes[i];
        while (n % primes[i] == 0) n /= primes[i];
    }
    if (n != 1)ans -= ans / n;
    return ans;
}

ll mpow(ll a, ll b, ll m) {
    if (b == 0) return 1 % m;
    if (b == 1) return a % m;

    ll r = mpow(a, b >> 1, m);
    r = (r * r) % m;
    if (b & 1)r = (r * a) % m;
    return r;
}

ll solve_normal(ll n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return mpow(n, solve_normal(n-1), 1000000000LL);
}

ll solve(ll n, ll m) {
    if (m == 1) return 0;

    // TIL: Eulers theorem can be used if exponent is larger than log2 of modulus.
    if (n <= 5) {
        return mpow(n, solve_normal(n - 1), m);
    }

    ll p = phi(m);
    ll a = solve(n - 1, p);
    return mpow(n, a + p, m);
}

void sieve() {
    memset(isp, 1, sizeof isp);

    isp[0] = isp[1] = 0;

    for (ll i = 2; i < N; ++i) if (isp[i]) {
        primes.push_back(i);
        for (ll j = i * i; j < N; j += i)isp[j] = 0;
    }
}

int main() {
    sieve();

    ll n, m;
    cin >> n >> m;
    cout << solve(n, m) << endl;
}
