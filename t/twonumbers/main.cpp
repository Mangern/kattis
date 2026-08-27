#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>

const int mxN = 1e7+5;
bitset<mxN> has;

int main() {
    ll n;
    scanf("%lld", &n);

    ordered_set mc;
    vector<ll> a(n);
    ll sum = 0;
    for (auto &x: a) {
        scanf("%lld", &x);
        mc.insert(x);
        sum += x;
        has.set(x);
    }
    ll adiff; double mdiff;
    scanf("%lld%lf", &adiff, &mdiff);

    ll avg_old = sum / n;

    ll avg_new = avg_old + adiff;

    sort(begin(a), end(a));

    auto med = [&] () {
        ll cnt = mc.size();

        // 0 1 2 3 4
        if (cnt & 1) {
            return (double)(*mc.find_by_order(cnt / 2));
        }
        ll l = *mc.find_by_order(cnt / 2 - 1);
        ll r = *mc.find_by_order(cnt / 2);
        return double(l + r) / 2.0;
    };

    double med_old = med(); 

    for (ll x1 : a) {
        ll x2 = sum - x1 - avg_new * (n - 2);
        if (x2 <= x1) continue;
        if (x2 >= mxN) continue;
        if (!has.test(x2)) continue;
        mc.erase(mc.find(x1));
        mc.erase(mc.find(x2));

        double med_new = med();

        if (med_old + mdiff == med_new) {
            printf("%lld %lld\n", x1, x2);
        }

        mc.insert(x1);
        mc.insert(x2);
    }
}
