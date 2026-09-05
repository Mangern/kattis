#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;

    vector<ll> t(n), s(n);
    for (auto& x : t) cin >> x;
    for (auto& x : s) cin >> x;

    vector<pair<ll,ll>> a;
    for (int i = 0; i < n; ++i) {
        if (s[i] == -1) continue;
        a.emplace_back(s[i],t[i]);
    }
    sort(begin(a), end(a));

    auto can = [&] (ll m) {
        ll st = 0;
        for (auto [s, t] : a) {
            st += t;
            if ((st + m - 1) / m > s)
                return false;
        }
        return true;
    };

    ll lo = 1;
    ll hi = 2e9;

    while (lo < hi) {
        ll mid = (lo + hi) / 2;

        if (can(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo << endl;
}
