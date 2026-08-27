#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll ans = 0;

    ll r;
    cin >> r;
    for (ll x = 0; x <= r; ++x) {
        ll y = floor(sqrt(r*r-x*x));
        y = 2 * y + 1;
        if (x == 0)ans += y;
        else ans += 2 * y;
    }
    cout << ans << endl;
}
