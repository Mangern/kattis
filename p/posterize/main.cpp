#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll cnt[258];
// dp[k][i]: Place k, last at i
ll dp[258][258];

int main() {
    int d, k;
    cin >> d >> k;

    for (int i = 0; i < d; ++i) {
        int r, p;
        cin >> r >> p;
        cnt[r] = p;
    }

    for (ll i = 0; i < 256; ++i) {
        ll sm = 0;

        for (ll j = 0; j < 256; ++j) {
            sm += cnt[j] * (i - j) * (i - j);
        }
        dp[1][i] = sm;
    }

    for (ll j = 2; j <= k; ++j) {
        for (ll i = j-1; i < 256; ++i) {
            dp[j][i] = numeric_limits<ll>::max();
            for (ll prv = i - 1; prv >= j - 2; --prv) {
                ll ret = dp[j-1][prv];

                for (ll x = prv + 1; x < 256; ++x) {
                    if (abs(x-i) <= abs(x-prv)) {
                        ret -= cnt[x] * (x - prv) * (x - prv);
                        ret += cnt[x] * (x - i) * (x - i);
                    }
                }

                if (ret < dp[j][i]) {
                    dp[j][i] = ret;
                } else ;
            }
        }
    }

    cout << *min_element(dp[k]+k-1, dp[k]+256) << endl;
}
