#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, s, k;
    cin >> n >> s >> k;

    vector<ll> a(n);
    for (auto &x : a) cin >> x;

    sort(begin(a), end(a));

    vector<ll> maxl(n, k);
    ll ans = 0;

    for (int i = 0; i < n; ++i) {
        ll mx = maxl[i];
        if (i < n - 1) {
            mx = min(mx, 2 * a[i+1] - s - 2 * a[i]);
        }
        if (mx < s) {
            cout << -1 << endl;
            return 0;
        }

        ans += mx;

        if (i < n - 1) {
            maxl[i+1] = min(maxl[i+1], 2 * a[i+1] - 2 * a[i] - mx);
        }
    }
    cout << ans << endl;
}
