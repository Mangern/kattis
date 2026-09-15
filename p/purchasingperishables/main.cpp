#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;

    ll ans = 1e15;

    for (ll l = 1; l <= n; ++l) {
        ll cur = 0;
        for (ll i = 0; i < n; i += l) {
            ll cnt = min(n - i, l);
            cur += cnt * a[i];
        }
        ans = min(ans, cur);
    }
    cout << ans << endl;
}
