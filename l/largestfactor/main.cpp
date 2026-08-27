#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 1e5;

ll spf[mxN];
vector<ll> primes;

int main() {
    for (ll i = 2; i < mxN; ++i) {
        if (spf[i]) continue;
        spf[i] = i;
        primes.push_back(i);
        for (ll j = i * i; j < mxN; j += i) {
            if (!spf[j]) spf[j] = i;
        }
    }

    ll n;
    cin >> n;

    for (ll p : primes) {
        while (n % p == 0 && n != p) {
            n /= p;
        }
        if (n == p) {
            cout << p << endl;
            return 0;
        }
    }

    if (n >= mxN) {
        cout << n << endl;
        return 0;
    }

    while (spf[n] != n) {
        n /= spf[n];
    }
    cout << n << endl;
}
