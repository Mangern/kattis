#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;

    vector<ll> rng;
    for (int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        rng.push_back(x*x+y*y);
    }
    sort(begin(rng), end(rng));
    ll q;
    cin >> q;
    while (q-->0) {
        ll d;
        cin >> d;

        cout << upper_bound(begin(rng), end(rng), d*d) - begin(rng) << endl;
    }
}
