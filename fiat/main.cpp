#include <iostream>
using namespace std;
using ll = long long;

const ll MOD = 1e9+7;

ll modpow(ll a, ll b) {
    if (b == 0) return 1;

    ll r = modpow(a, b >> 1);
    r = (r * r) % MOD;
    if (b & 1) r = (r * a) % MOD;
    return r;
}

int main() {
    ll n;
    cin >> n;

    ll cn = 1;

    for (int i = 0; i < n; ++i) {
        cn = ((4 * i + 2) * cn % MOD) * modpow(i + 2, MOD - 2) % MOD;
    }
    cout << cn << endl;
}
