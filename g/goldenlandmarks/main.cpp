#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;

    unordered_map<string, pair<ll, ll>> pos;

    for (int i = 0; i < n; ++i) {
        string s;
        ll x, y;
        cin >> s >> x >> y;
        pos[s] = {x, y};
    }

    ll px, py;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        auto [x, y] = pos[s];
        if (i > 0) {
            ans += abs(px - x) + abs(py - y);
        }
        px = x;
        py = y;
    }
    cout << ans << endl;
}
