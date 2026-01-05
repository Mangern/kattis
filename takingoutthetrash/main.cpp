#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, m;
    cin >> n >> m;
    multiset<ll> ms;
    for (int i = 0; i < n; ++i) {
        ll w;
        cin >> w;
        ms.insert(w);
    }

    ll ans = 0;
    for (auto it = --end(ms); ms.size();) {
        if (it == begin(ms)) {
            ++ans;
            ms.erase(it);
            continue;
        }

        auto l = ms.upper_bound(m - *it);
        if (l == begin(ms)) {
            ++ans;
            auto nxt = prev(it);
            ms.erase(it);
            it = nxt;
            continue;
        }
        l = prev(l);
        if (l == it) l = prev(l);

        ++ans;
        ms.erase(l);
        auto nxt = prev(it);
        ms.erase(it);
        it = nxt;
    }
    cout << ans << endl;
}
