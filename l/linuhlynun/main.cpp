#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll, 2>;

int main() {
    ll n;
    cin >> n;
    vector<ii> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0] >> a[i][1];
    }
    sort(begin(a), end(a));

    ll pos = a[0][0];
    ll lcsum = a[0][1];
    ll rcsum = 0;
    ll tot = 0;

    for (int i = 1; i < n; ++i) {
        rcsum += a[i][1];
        tot += a[i][1] * (a[i][0] - a[0][0]);
    }
    ll ans = tot;
    ll ansi = 0;

    for (int i = 1; i < n; ++i) {
        tot += (a[i][0] - a[i-1][0]) * lcsum;
        tot -= (a[i][0] - a[i-1][0]) * rcsum;
        rcsum -= a[i][1];
        lcsum += a[i][1];
        if (tot < ans) {
            ans = tot;
            ansi = i;
        }
    }
    cout << a[ansi][0] << endl;
}
