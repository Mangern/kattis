#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, t;
    cin >> n >> t;
    vector<ll> a(n);
    for (auto & x: a)cin >> x;
    sort(begin(a),end(a));
    reverse(begin(a),end(a));
    for (int i = 0; i < n; ++i) {
        if (a[i] <= t * (n - i - 1)) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}
