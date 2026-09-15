#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll a, b;
    cin >> a >> b;

    ll ans = 0;
    for (ll k = 1; ; ++k) {
        ll d = k * b;
        if (d > a) break;
        if (a % d == 0) {
            ++ans;
        }
    }
    cout << ans << endl;
}
