#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll a, e, m;
    cin >> a >> e >> m;

    __int128 mod = m;

    __int128 ret = 1;

    for (ll i = 63; i >= 0; --i) {
        ret = (ret * ret) % m;
        if ((e >> i) & 1) {
            ret = (ret * a) % m;
        }
    }

    ll ans = ret;
    cout << ans << endl;
}
