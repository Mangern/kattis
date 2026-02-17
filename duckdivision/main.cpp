#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll d ,u;
    cin >> d >> u;
    ll ans = d;
    for (ll i = 2; i * i <= d && (d / i) >= u; ++i) {
        if (d % i == 0) {
            ans = d / i;
        }
    }
    cout << ans << endl;
}
