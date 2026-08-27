#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

int main() {
    ll n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    vector<ll> pref(n+1);
    vector<ll> suf(n+1);

    ll p = 0;

    ll cnt = 0;

    for (int i = 0; i < n; ++i) {
        p = (10 * p) % m;
        p = (p + s[i] - '0') % m;

        pref[i] = p;
    }

    p = 0;
    suf[n] = 0;

    ll mul = 1;
    for (int i = n - 1; i >= 0; --i) {
        p = (p + (mul * (s[i] - '0')) % m) % m;
        mul = (mul * 10) % m;
        suf[i] = p;
    }

    for (int i = 0; i < n; ++i) {
        if (pref[i] == 0 && suf[i+1] == 0)++cnt;
    }

    ll ans = (cnt>0);
    for (int i = 0; i < cnt - 1; ++i) {
        ans = (2 * ans) % MOD;
    }
    cout << ans << endl;
}
