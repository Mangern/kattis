#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 1e5+5;

ll n, k;
ll a[mxN];

bool check(ll wg) {
    ll ng = 1;
    ll sm = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > wg) return false;
        if (sm + a[i] > wg) {
            ++ng;
            sm = a[i];
        } else sm += a[i];
    }
    return ng <= k;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i)cin >> a[i];

    ll lo = 0;
    ll hi = 1e10;
    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo << endl;
}
