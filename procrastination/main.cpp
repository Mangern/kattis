#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll, 2>;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ii> a;
    for (int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        a.push_back({x, -y});
    }

    sort(begin(a), end(a));

    ll ans = 0;

    for (auto [t, g] : a) {
        if (m < t) break;
        m -= t;
        ans -= g;
    }
    cout << ans << endl;
}
