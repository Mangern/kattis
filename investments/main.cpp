#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, m;
    cin >> n >> m;

    vector<pair<ll, ll>> a(n);
    for (auto &[c, r] : a) cin >> c >> r;
    sort(begin(a), end(a));

    ll st = m;

    for (auto [c, r] : a) {
        if (c > m) break;
        if (c < r) {
            m -= c;
            m += r;
        }
    }
    cout << m - st << endl;
}
