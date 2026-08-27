#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 2501;

ll a[mxN];

int main() {
    ll n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i)cin >> a[i];

    ll ans = 0;

    for (;;) {
        bool bad = 0;
        for (ll i = 1; i < n; ++i) {
            if (a[i] < a[i-1]) {
                bad = 1;
                break;
            }
        }
        if (!bad) break;
        ++ans;

        for (int i = 0; i + k <= n; ++i) {
            sort(a+i, a+i+k);
        }
    }
    cout << ans << endl;
}
