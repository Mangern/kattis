#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 2004;
const int mxT = 1e5+4 + 40000 * 1.5;

const int INF = numeric_limits<int>::max();

int n, t;

int l[mxN];
ll dp[mxT]; // min number of runs to make a total time
int cf[mxT];


int main() {

    for (int i = 0; i < mxT; ++i)dp[i] = INF;

    cin >> n >> t;

    for (int i = 0; i < n; ++i) {
        cin >> l[i];
        l[n+i] = (l[i] + (l[i] >> 1));
    }

    dp[0] = 0;

    for (int i = 0; i < (n << 1); ++i) {
        int cost = (i >= n ? 2 : 1);
        for (int j = 0; j <= t; ++j) {
            if (dp[j] + cost < dp[j + l[i]]) {
                dp[j + l[i]] = dp[j] + cost;
                cf[j + l[i]] = i;
            }
        }
    }

    int best;
    for (best = t; best < mxT; ++best) {
        if (dp[best] != INF)break;
    }

    cout << best << " " << dp[best] << endl;

    vector<int> ans(n, 0);

    while (best) {
        ans[cf[best] % n] += l[cf[best]];
        best -= l[cf[best]];
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " \n"[i == n - 1];
    }

    return 0;
}
