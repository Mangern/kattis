#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// calculate a * b / c
// or return zero if not divisible
ll muldiv(ll a, ll b, ll c) {
    // TODO: Overflow
    __int128 p = (__int128)a * b;
    if (p % c != 0) return false;
    __int128 r = p / c;
    if (r > 1e15) return false;
    return (ll)r;
}

int main() {
    int n, m;
    cin >> m >> n;

    vector<ll> tim(m);
    for (auto &t : tim) {
        cin >> t;
    }
    ll sub = tim[0];
    for (auto & t : tim) t -= sub;

    vector<ll> xs(n);
    for (auto &x : xs) {
        cin >> x;
    }

    sub = xs[0];
    for (auto &x : xs) x -= sub;

    vector<ll> ans;
    for (int i = 0; i + m <= n; ++i) {
        ll a = xs[i+1] - xs[i];
        ll b = tim[1];
        bool fail=0;
        for (int j = 2; j < m; ++j) {
            ll dt = tim[j] - tim[j-1];
            ll dx = muldiv(dt, a, b);
            if (!dx){
                fail=1;
                break;
            }
            ll nxt = xs[i+j-1]+dx;
            if (nxt != xs[i+j]) {
                fail=1;
                break;
            }
        }
        if (!fail) {
            ans.push_back(a);
        }
    }
    sort(begin(ans), end(ans));
    ans.erase(unique(begin(ans),end(ans)), end(ans));
    cout << ans.size() << endl;
    for (auto x : ans)cout << x << ' ';
    cout << endl;
}
