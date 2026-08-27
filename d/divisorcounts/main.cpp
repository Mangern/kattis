#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 3e6+6;

ll ans[mxN];

int main() {
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = i; j <= n; j += i) {
            ++ans[j];
        }
    }
    for (ll i = 1; i <= n; ++i) {
        cout << ans[i] << '\n';
    }

}
