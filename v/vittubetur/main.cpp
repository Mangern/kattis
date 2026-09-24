#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mxN = 1e6+6;

ll dp[mxN];
ll spf[mxN];

int main() {

    for (ll i = 2; i < mxN; ++i) {
        if (spf[i]) continue;
        spf[i] = i;
        for (ll j = i * i; j < mxN; j += i) {
            if (!spf[j])spf[j] = i;
        }
    }

    for (ll i = 2; i < mxN; ++i) {
        ll x = i;
        dp[i] = dp[i-1];
        while (x > 1) {
            ++dp[i];
            x /= spf[x];
        }
    }

    ll n;
    while (cin >> n) {
        cout << dp[n] <<'\n';
    }
}
