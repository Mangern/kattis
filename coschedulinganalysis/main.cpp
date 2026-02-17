#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll, 2>;

int main() {
    vector<ii> evts;

    int m;
    cin >> m;

    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;

        for (int j = 0; j < k; ++j) {
            ll a, b;
            cin >> a >> b;

            evts.push_back({a, 1});
            evts.push_back({b, -1});
        }
    }
    sort(begin(evts), end(evts));

    ll nc = 0;
    ll ans = 0;
    ll pt = 0;
    for (int i = 0; i < evts.size(); ) {
        int j;
        ll t = evts[i][0];

        if (nc > 1) {
            ans += t - pt;
        }

        for (j = i; j < evts.size(); ++j) {
            if (evts[j][0] != t) break;
            nc += evts[j][1];
        }
        pt = t;
        i = j;
    }
    cout << ans << endl;
}
