#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using tup = array<ll,3>;

int main() {
    ll n,t,k;
    cin >> n >> t >> k;

    vector<ll> cnt(t,0);
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        ++cnt[x-1];
    }

    vector<ll> a(t), b(t);
    for (int i = 0; i < t; ++i) {
        cin >> a[i] >> b[i];
    }

    vector<tup> deltas;
    for (int i = 0; i < t; ++i) {
        ll keep = -(2 - cnt[i]) * a[i];
        ll sell = cnt[i] * b[i];

        deltas.push_back({keep - sell, keep, sell});
    }

    sort(begin(deltas), end(deltas));

    ll ans = 0;
    for (int i = 0; i < t; ++i) {
        if (t - i <= k) {
            ans += deltas[i][1];
        } else {
            ans += deltas[i][2];
        }
    }
    cout << ans << endl;
}
