#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (auto &b : a) cin >> b;

    sort(begin(a), end(a));
    int i = 0;
    for (i = 1; i < n; ++i) {
        if (a[i] + a[i-1] > x) {
            break;
        }
    }
    cout << i << endl;
}
