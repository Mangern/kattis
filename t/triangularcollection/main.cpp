#include <bits/stdc++.h>
using namespace std;
using ll =long long;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;

    sort(begin(a), end(a));

    ll ans = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ll num = 0;
            for (ll k = j + 1; k < n; ++k) {
                if (a[k] < a[i] + a[j])++num;
                else break;
            }
            ans += (1LL<<num) - 1;
        }
    }
    cout << ans << endl;
}
