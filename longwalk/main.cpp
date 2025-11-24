#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, m;
ll mid;

ll dist(ll u, ll v) {
    deque<ll> pu, pv;
    for (;;) {
        pu.push_back(u);
        if (u == 0) break;
        u &= (~mid);
        u <<= 1;
    }
    for (;;) {
        pv.push_back(v);
        if (v == 0) break;
        v &= (~mid);
        v <<= 1;
    }
    while (pu.size() && pv.size() && pu.back() == pv.back()) {
        pu.pop_back();
        pv.pop_back();
    }

    return pv.size() + pu.size();
}

int main() {
    cin >> n >> m;

    mid = (1LL<<(n-1));

    ll prv;
    cin >> prv;

    ll ans = 0;
    for (int i = 0; i < m - 1; ++i) {
        ll u;
        cin >> u;

        ans += dist(u, prv);
        prv = u;
    }
    cout << ans << endl;
}
