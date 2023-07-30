#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, e;
    cin >> n >> e;

    e = (1<<e);
    ll bg = 10;
    while (bg < e)bg *= 10;
    ll ans = 0;
    for (ll i = 1; i <= n; ++i) {
        ll x = i;

        while (x) {
            if (x % bg == e) {
                ++ans;
                break;
            }
            x /= 10;
        }
    }
    cout << ans << endl;
    return 0;
}
