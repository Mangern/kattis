#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;

    ll lo = 0;
    ll hi = *max_element(begin(a), end(a));

    while (lo < hi) {
        ll mid = (lo + hi + 1) / 2;

        ll take = 0;
        for (auto x : a) {
            take += max(0LL, x - mid);
        }

        if (take >= m) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    cout << lo<< endl;
}
