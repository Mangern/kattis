#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, m;
    cin >> n >> m;

    vector<pair<ll, ll>> arr(n);
    for (auto &p : arr) cin >> p.first;
    for (auto &p : arr) cin >> p.second;

    sort(begin(arr), end(arr));

    for (auto [c, d] : arr) if (d > c) {
        if (c > m) break;
        m -= c;
        m += d;
    }
    cout << m << endl;
}
