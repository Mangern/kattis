#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll p, k, n;
    cin >> p >> k >> n;

    vector<ll> a(n);
    for (auto &x : a) cin >> x;

    sort(begin(a), end(a));
    reverse(begin(a), end(a));

    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        ll key = (i+k) / k;
        ans += key * a[i];
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case #" << tc << ": ";
        solve();
    }
}
