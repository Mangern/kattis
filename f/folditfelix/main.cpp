#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll = long long;
using ii = array<ll, 2>;

const int mxN = 2e5+5;
const ll INF = numeric_limits<ll>::max() / 100;

int n;
ll a[mxN];
ll mp[mxN];
ll p[mxN];
int amax[mxN];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    p[0] = a[0];

    for (int i = 1; i < n; ++i) {
        p[i] = p[i-1] + a[i];
    }
    p[n] = INF;

    memset(amax, -1, sizeof amax);

    int bj = -1;

    for (int i = 0; i < n; ++i) {
        ll suf = a[i];
        mp[i] = a[i] + (i>0?mp[i-1]:0);
        bj = max(bj, amax[i]);

        if (bj >= 0) {
            // sum[bj+1, i]
            mp[i] = min(mp[i], p[i]-p[bj]);
        }

        int nj;

        // find smallest j such that sum[i+1, j] >= mp[i]
        ll lo = i + 1;
        ll hi = n;

        while (lo < hi) {
            ll mid = (lo + hi) / 2;

            ll sm = p[mid] - p[i];

            if (sm >= mp[i]) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        if (lo < n) {
            amax[lo] = max(amax[lo], i);
        }
    }

    ll ans = mp[n-1];

    ll suf = a[n-1];

    for (int i = n - 2; i >= 0; --i) {
        ans = min(ans, max(mp[i], suf));

        suf += a[i];
    }
    cout << ans << endl;
}
