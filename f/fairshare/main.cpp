#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    ll sa = 0;
    ll sb = 0;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        sa += a[i];
        sb += b[i];
    }

    for (int i = 0; i < n; ++i) {
        ll get = sa - a[i];
        ll rem = sb - get;
        if (rem <= b[i]) {
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << "impossible" << endl;
}
