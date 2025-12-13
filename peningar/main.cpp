#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 1e5+5;

ll a[mxN];

int main() {
    ll n, d;
    cin >> n >> d;

    for (int i = 0; i < n; ++i) cin >> a[i];

    ll pos = 0;

    ll ans = 0;

    while (a[pos] > 0) {
        ans += a[pos];
        a[pos] = 0;
        pos = (pos + d) % n;
    }

    cout << ans << endl;
}
