#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, k;
    cin >> n >> k;

    ll cur = 0;
    ll ans = 0;
    ll mul = 10;
    for (ll i = 1; i <= n; ++i) {
        if (i % mul == 0) {
            mul *= 10;
        }
        cur = ((cur * (mul % k)) % k + i) % k;
        if (!cur)++ans;
    }
    cout << ans << endl;
}
