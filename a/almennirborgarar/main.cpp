#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, m;
    cin >> n >> m;

    vector<ll> ts(n);
    for (auto &t: ts) cin >> t;

    auto check = [&](ll x) {
        ll cnt = 0;
        for (auto t : ts) {
            // t * k <= x
            // k <= x / t
            cnt += x / t;
        }
        return cnt >= m + 1;
    };

    ll lo = 0;
    ll hi = (m + 1) * *min_element(begin(ts), end(ts));

    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        if (check(mid)) {
            hi = mid;
        } else lo = mid + 1;
    }
    cout << lo << endl;
}
