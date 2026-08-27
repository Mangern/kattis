#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n ,c;
    cin >> n >> c;
    vector<ll> a(n);
    for (auto& x: a) cin >> x;

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ll cur = 0;
        int j;
        ll cnt = 0;
        for (j = i; j < n; ++j) {
            if (cur + a[j] > c) continue;
            cur += a[j];
            ++cnt;
        }
        ans = max(ans, cnt);
    }

    cout << ans << endl;
}
