#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, c;
    cin >> n >> c;

    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    sort(begin(a), end(a));

    ll l = 0;
    ll r = n - 1;

    ll ans = 0;
    while (l <= r) {
        ++ans;
        if (l < r && a[l] + a[r] <= c) {
            ++l;
        }
        --r;
    }
    cout << ans << endl;
}
