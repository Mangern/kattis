#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

#define all(v) begin(v), end(v)

ll n, m, x, y;

bool check(const vll &a, const vll &b, ll take) {
    vll space(n, x);
    for (int i = 0; i < take; ++i)space[i] = y;

    int sptr = 0;

    for (ll x : b) {
        while (sptr < n && (a[sptr] < x || space[sptr] == 0))++sptr;
        if (sptr >= n) return false;
        --space[sptr];
    }
    return true;
}

int main() {
    cin >> n >> m >> x >> y;

    vector<ll> a(n);
    for (auto &x : a)cin >> x;
    vector<ll> b(m);
    for (auto &x : b)cin >> x;
    sort(all(a));
    sort(all(b));


    if (!check(a,b,0)) {
        cout << "impossible" << endl;
        return 0;
    }

    ll lo = 0, hi = n;

    while (lo < hi) {
        ll mid = (lo + hi + 1) / 2;
        if (check(a,b,mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    cout << lo << endl;
}
