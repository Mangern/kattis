#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    unordered_map<ll, ll> cnt;
    ll sm = 0;
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        ++cnt[x];
        sm += x;
    }

    ll q;
    cin >> q;

    ll inf = 0;
    while (q-->0) {
        string cmd;
        cin >> cmd;

        if (cmd == "SET") {
            ll x, y;
            cin >> x >> y;

            x -= inf;
            y -= inf;
            ll dx = cnt[x];
            sm += dx * (y - x);
            cnt[y] += dx;
            cnt[x] -= dx;
        } else {
            ll x;
            cin >> x;
            inf += x;
        }

        cout << sm + inf * n << endl;
    }
}
