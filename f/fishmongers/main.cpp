#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll, 2>;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> w(n);
    for (auto & x : w) cin >> x;
    sort(rbegin(w), rend(w));
    vector<ii> mong(m);
    for (auto &[p, x] : mong) cin >> x >> p;
    sort(rbegin(mong), rend(mong));

    ll ans = 0;
    int fptr = 0;
    for (auto [p,x] : mong) {
        for (int i = 0; i < x; ++i) {
            ans += p * w[fptr++];
            if (fptr == n) break;
        }
        if (fptr == n) break;
    }
    cout << ans << endl;
}
