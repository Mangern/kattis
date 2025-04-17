#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 64;

ll n, k, q;

int max_depth;

ll depth(ll x) {
    ll d = 0;
    while (x) {
        ++d;
        x = (x - 1) / k;
    }
    return d;
}

ll par(ll x) {
    return (x-1) / k;
}


ll query(ll x, ll y) {
    ll ans = 0;

    while (depth(x) > depth(y)) {
        x = par(x);
        ++ans;
    }
    while (depth(y) > depth(x)) {
        y = par(y);
        ++ans;
    }

    while (x != y) {
        ans += 2;
        x = par(x);
        y = par(y);
    }

    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> k >> q;

    while (q-->0) {
        ll x, y;
        cin >> x >> y, --x, --y;

        if (k == 1) {
            cout << abs(x - y) << endl;
            continue;
        }

        cout << query(x,y) << endl;
    }
}
