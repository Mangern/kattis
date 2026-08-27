#include <bits/stdc++.h>
#include <limits>

using namespace std;
using ll = long long;

vector<pair<ll, ll>> pfs(ll n) {
    vector<pair<ll, ll>> result;
    for (ll p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;

        ll r = 0;

        while (n % p == 0) {
            ++r;
            n /= p;
        }

        result.push_back({p, r});
    }

    if (n > 1) {
        result.push_back({n, 1});
    }

    return result;
}

int main() {
    ll n, m;
    cin >> n >> m;

    auto facs = pfs(n);

    ll k = numeric_limits<ll>::max();

    for (auto [p, r] : pfs(n)) {
        ll l = 0;

        ll ml = p;

        while (ml <= m) {
            l += m / ml;
            ml *= p;
        }

        k = min(k, l / r);
    }
    cout << k << endl;
}
