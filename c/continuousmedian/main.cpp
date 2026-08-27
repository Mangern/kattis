#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int t;
    cin >> t;
    while (t-->0) {
        ll n;
        cin >> n;

        multiset<ll> lo, hi;
        ll ans = 0;

        for (ll i = 0; i < n; ++i) {
            ll a;
            cin >> a;

            if (lo.size() == hi.size()) {
                lo.insert(a);
                hi.insert(*--lo.end());
                lo.erase(--lo.end());
                ans += *hi.begin();
            } else {
                if (a <= *hi.begin())lo.insert(a);
                else {
                    lo.insert(*hi.begin());
                    hi.erase(hi.begin());
                    hi.insert(a);
                }

                ans += (*--lo.end() + *hi.begin())/2;
            }
        }
        cout << ans << endl;
    }
}
