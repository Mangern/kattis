#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mxN = 600005;

ll n;
// how many subsets with sum i
ll nsum[mxN];
ll p[65];

int main() {
    cin >> n;

    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        sum += p[i];
    }

    sort(p, p + n);
    reverse(p, p + n);

    ll ans = 0;
    ll floorsum = sum / 2;
    ll ceilsum = (sum + 1) / 2;
    assert(floorsum + ceilsum == sum);
    nsum[0] = 1;

    for (ll i = 0; i < n; ++i) {
        // 2 * lower - 2 <= sum
        // 2 * lower > sum

        for (ll j = 0; j < mxN; ++j) {
            // if adding p[i] makes it a majority, and it was not already a majority, good
            if (2 * (j + p[i]) > sum && 2 * j <= sum) {
                ans += nsum[j];
            }
        }

        for (ll s = mxN - 1; s >= 0; --s) {
            if (s + p[i] < mxN) {
                nsum[s+p[i]] += nsum[s];
            }
        }
    }

    cout << ans << endl;
}
