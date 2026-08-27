#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, s, a;
    cin >> n >> s >> a;

    vector<ll> h(n);
    for (auto& x : h) cin >> x;

    sort(begin(h), end(h));

    vector<ll> nh(n);

    auto check = [&](ll cnt) {
        for (int i = 0; i < n; ++i) {
            nh[i] = max(0LL, h[i] - a * cnt);
        }
        for (int i = n - 1; i >= 0; --i) {
            ll need = (nh[i] + s - 1) / s;
            if (need > cnt)return false;
            cnt -= need;
        }
        return true;
    };

    ll lo = 1;
    ll hi = 1e10+7;

    while (lo < hi) {
        ll mid = (lo + hi) / 2;

        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo << endl;
}
