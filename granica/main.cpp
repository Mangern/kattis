#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    set<ll> poss;

    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    sort(begin(a), end(a));

    ll d = a[1] - a[0];

    for (ll m = 2; m * m <= d;++m) {
        if (d % m == 0) {
            poss.insert(m);
            poss.insert(d / m);
        }
    }
    poss.insert(d);

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            set<ll> keep;
            ll d = a[j]-a[i];
            for (auto m : poss) {
                if (d % m == 0) {
                    keep.insert(m);
                }
            }
            swap(poss,keep);
        }
    }

    for (auto m : poss) {
        ll x = a[0] % m;

        bool fail = 0;
        for (int i = 1; i < n; ++i) {
            if (a[i] % m != x)fail = 1;
        }
        if (!fail)cout << m << " ";
    }
    cout << endl;
}
