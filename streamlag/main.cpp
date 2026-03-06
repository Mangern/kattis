#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<ll> play(n+1, numeric_limits<ll>::max());

    vector<bool> vis(n, 0);

    for (int i = 0; i < n; ++i) {
        ll t, j;
        cin >> t >> j;

        play[j] = t;
    }

    ll ans = play[1] - 1;
    for (ll i = 2; i <= n; ++i) {
        play[i] = max(play[i], play[i-1]+1);
        ans += play[i] - play[i-1] - 1;
    }
    cout << ans << endl;
}
