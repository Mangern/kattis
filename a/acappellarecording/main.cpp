#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, d;
    cin >> n >> d;

    vector<ll> a(n);
    for (auto & x : a) cin >> x;

    sort(begin(a), end(a));

    ll ans = 0;

    for (int i = 0; i < n; ) {
        int j;
        ++ans;
        for (j = i; j < n; ++j) {
            if (a[j] - a[i] > d) break;
        }
        i = j;
    }
    cout << ans << endl;
}
