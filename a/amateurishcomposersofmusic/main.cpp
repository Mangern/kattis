#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll, 2>;

int main() {
    ll n, m;
    cin >> n >> m;

    vector<ll> g(n);
    for (auto &x : g) cin >> x;

    vector<ii> s(m);

    for (ll i = 0; i < m; ++i) {
        cin >> s[i][0];
        s[i][1] = i;
    }
    sort(begin(s), end(s));
    vector<ll> ans(m);

    ll j = 0;
    for (ll i = 0; i < m; ++i) {
        auto [x, id] = s[i];
        while (j + 1 < n && abs(g[j+1]-x) <= abs(g[j]-x))++j;

        ans[id] = g[j] - x;
    }
    for (auto x : ans)cout << x << '\n';
}
