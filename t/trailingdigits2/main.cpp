#include <bits/stdc++.h>
using namespace std;
using ll = __int128;

const ll MOD = 1e10;

ll mpow(ll a, long long b) {
    if (b == 0) return 1;
    ll r = mpow(a, b >> 1);
    r = (r * r) % MOD;
    if (b & 1) r = (r * a) % MOD;
    return r;
}

int main() {
    ll ans = 0;
    long long n;
    cin >> n;

    for (ll i = 1; i <= n; ++i) {
        ans += mpow(i, i);
        if (ans >= MOD) ans -= MOD;
    }
    long long ret = ans;
    cout << ret << endl;
}

