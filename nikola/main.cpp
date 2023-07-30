#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll,2>;

const int mxN = 1001;

int n;
ll a[mxN];
ll dp[mxN][mxN];

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i)cin >> a[i];

    for (int i = 0; i < mxN; ++i) {
        for (int j = 0; j < mxN; ++j) {
            dp[i][j] = 10000000000000;
        }
    }

    dp[0][0] = 0;

    queue<ii> q;
    q.push({0,0});

    while (!q.empty()) {
        auto [i, l] = q.front();
        q.pop();

        if (i - l >= 0) {
            if (dp[i-l][l] > dp[i][l] + a[i-l]) {
                dp[i-l][l] = dp[i][l]+a[i-l];
                q.push({i-l,l});
            }
        }
        if (i+l+1 < n) {
            if (dp[i+l+1][l+1] > dp[i][l]+a[i+l+1]) {
                dp[i+l+1][l+1] = dp[i][l]+a[i+l+1];
                q.push({i+l+1,l+1});
            }
        }
    }

    ll ans = numeric_limits<ll>::max();
    for (int i= 0; i < mxN; ++i) {
        ans = min(ans,dp[n-1][i]);
    }
    cout << ans << endl;
}
