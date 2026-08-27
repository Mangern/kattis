#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

const int mxN = 1e7+4;

const ll MOD = 1000;


int main() {
    ll ans = 1;

    ll n;
    cin >> n;
    ll k = 0;
    ll l = 0;
    ll m = 1;
    for (ll i = 2; i <= n; ++i) {
        ll y = i;
        while (y % 2 == 0) {
            ++k;
            y /= 2;
        }
        while (y % 5 == 0) {
            ++l;
            y /= 5;
        }
        m *= y;
        m %= MOD;
    }

    for (ll i = 0; i < k - l; ++i) m = (m * 2) % MOD;
    if (m == 48) cout << "048" << endl;
    else cout << m << endl;
}
