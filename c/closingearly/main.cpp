#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll r, s, n;
    cin >> r >> s >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;

    if (r == 0) {
        cout << 0 << endl;
        return 0;
    }

    ll sm = s - r;
    for (int i = 0; i < n; ++i) {
        sm += a[i];
        sm %= s;
        if (sm == 0) {
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
