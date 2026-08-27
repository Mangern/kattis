#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll v;
    cin >> v;

    ll ans = numeric_limits<ll>::max();
    for (ll l = 1; l <= 1000; ++l) for (ll w = 1; w <= 1000; ++w) {
        // l * w * h == v
        if (v % (l * w) != 0) continue;
        ll h = v / (l * w);

        ll ar = l * w * 2 + l * h * 2 + w * h * 2;
        ans = min(ans, ar);
    }
    cout << ans << endl;
}
