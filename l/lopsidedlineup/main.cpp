#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;

    vector<ll> sm(n);
    for (int i = 0; i < n; ++i) {
        ll &s = sm[i];
        s = 0;
        for (int j = 0; j < n; ++j) {
            ll x;
            cin >> x;
            s += x;
        }
    }
    sort(begin(sm), end(sm));
    ll ans = accumulate(begin(sm)+n/2, end(sm), 0LL) - accumulate(begin(sm), begin(sm)+n/2, 0LL);
    ans /= 2;
    cout << ans << endl;
}
