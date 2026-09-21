#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll n, v;
    cin >> n >> v;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;

    vector<ll> b;

    ll lb = v + 1;
    for (int i = 0; i < n; ++i) {
        if (a[i] >= lb) {
            b.push_back(a[i]);
            ++lb;
        }
    }

    ll mx = 0;
    for (int i = (int)b.size() - 1; i >= 0; --i) {
        b[i] = max(mx, b[i]);
        mx = max(mx, b[i]);
    }
    cout << b.size() << endl;
    for (auto x : b) cout << x << ' ';
    cout << endl;
}
