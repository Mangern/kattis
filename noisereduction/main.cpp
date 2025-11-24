#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, t;
    cin >> n >> t;

    vector<ll> a(n);
    vector<ll> p(1, 0);

    for (auto &x : a) {
        cin >> x;
        p.push_back(p.back() + x);
    }

    ll g;
    for (g = 1; g <= n; ++g) {
        ll noise = 0;

        for (ll i = 2*g; i <= n; i += g) {
            ll s = (p[i] - p[i-g])/g;
            ll prev = (p[i-g] - p[i-2*g])/g;
            noise = max(noise, abs(s-prev));
        }

        if (noise <= t)break;
    }

    cout << g << endl;
}
