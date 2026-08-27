#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int T;
    cin >> T;
    while (T-->0) {
        ll n, c;
        cin >> n >> c;
        vector<ll> neg;
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            ll x;
            cin >> x;
            if (x < 0)neg.push_back(-x);
            else ans += x;
        }

        sort(neg.rbegin(), neg.rend());

        for (ll i = 0; i < (ll)neg.size(); ++i) {
            ll delta = neg[i] - (i+1)*c;
            if (delta >= 0) {
                ans += delta;
            } else break;
        }
        cout << ans << endl;
    }
}
