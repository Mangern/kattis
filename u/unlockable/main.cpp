#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    vector<set<ll>> pws(32);

    ll n, a;
    cin >> n >> a;

    ll abig=1;
    ll xbig=0;

    for (int i = 0; i < 32; ++i) {
        abig *= a;
        ++xbig;

        if (abig > 1e9) break;
    }

    vector<ll> bs(n);
    for (auto &x : bs) cin >> x;

    for (auto b : bs) {
        ll divp = abig;

        for (ll x = xbig; x > 0; --x) {
            if (b % divp == 0) {
                pws[x].insert(b / divp);
            }
            divp /= a;
        }
    }

    ll ans = 0;

    for (int i = 0; i < 32; ++i) {
        ans += pws[i].size();
    }
    cout << ans << endl;
}
