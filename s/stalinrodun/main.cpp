#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;

    vector<ll> seq(n, 0);
    ll start = n - 1;

    // 0:
    // 1: 1
    // 2: 2 3

    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;

        ll idx = upper_bound(begin(seq)+start, end(seq), x) - begin(seq) - 1;
        // cout << idx << endl;
        // assert(seq[idx] <= x);
        seq[idx] = x;
        if (idx == start)--start;
    }

    cout << n - start - 1 << endl;
}
