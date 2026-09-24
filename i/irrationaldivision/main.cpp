#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using state = tuple<ll, ll, ll>;

unordered_map<ll, ll> dp;

ll getkey(const state& s) {
    auto [p, q, tl] = s;
    if (tl == -1) {
        return p * 101 + q;
    }
    return 101 * 101 + p * 101 + q;
}


ll solve(ll p, ll q, ll top_left) {
    if (p == 0 || q == 0) {
        return 0;
    }
    ll key = getkey({p,q,top_left});
    if (dp.count(key)) {
        return dp[key];
    }
    ll &ret = dp[key];
    ret = -100000;

    for (ll c = 1; c <= q; ++c) {
        ll gain = ((c * p % 2 == 0) ? 0 : top_left);

        ll sub = solve(q - c, p, c % 2 == 0 ? top_left : -top_left);
        // sister - me = sub
        //
        // new_me - sister = (me' + gain) - sister = gain - sub
        ret = max(ret, gain - sub);
    }
    // cout << p << " " << q << " " << top_left << " -> " << ret << endl;
    return ret;
}

int main() {
    ll p,q;
    cin >> p >> q;
    cout << solve(p,q,1) << endl;
}
