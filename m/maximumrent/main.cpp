#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll a, b, m, s;
    cin >> a >> b >> m >> s;

    ll ans = 0;
    for (ll x = 1; x <= m; ++x) {
        ll y_min = max(1LL, s - 2 * x);
        ll y_max = m - x;
        if (y_max < y_min) continue;
        ans = max(ans, a * x + b * y_max);
    }
    cout << ans << endl;
}
