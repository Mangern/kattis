#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct pqt {
    ll x;
    list<ll>::iterator it;

    bool operator<(const pqt &other) const {
        return x > other.x;
    }
};

int main() {
    ll n;
    cin >> n;

    list<ll> a;

    priority_queue<pqt> pq;

    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;

        a.push_back(x);
        auto it = --a.end();
        pq.push({x, it});
    }

    ll ans = 0;

    while (a.size() > 1) {
        auto [x, i1] = pq.top();
        pq.pop();

        list<ll>::iterator i2;

        if (i1 == begin(a)) {
            i2 = next(i1);
        } else if (next(i1) == end(a)) {
            i2 = prev(i1);
        } else {
            i2 = prev(i1);
            if (*next(i1) < *i2) {
                i2 = next(i1);
            }
        }

        ll cost = *i2;
        ans += cost;
        a.erase(i1);
    }
    cout << ans << endl;
}
