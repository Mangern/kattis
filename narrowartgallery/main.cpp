#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 205;


ll val[mxN][2];
ll dp[mxN][mxN][3];

void testCase() {
    ll n, k;
    cin >> n >> k;
    if (n+k==0)exit(0);
    // 00, 01, 10
    for (int i = 0; i < n; ++i) {
        cin >> val[i][0] >> val[i][1];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n; ++j) {
            dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = numeric_limits<ll>::min();
        }
    }

    dp[0][0][0] = val[0][0] + val[0][1];
    dp[0][1][1] = val[0][1];
    dp[0][1][2] = val[0][0];

    for (ll i = 1; i < n; ++i) {
        for (ll j = 0; j <= i+1; ++j) {
            dp[i][j][0] = max(
                dp[i-1][j][0], 
                max(dp[i-1][j][1], dp[i-1][j][2])
            ) + val[i][0] + val[i][1];

            if (j>0) {
                dp[i][j][1] = val[i][1] + max(dp[i-1][j-1][1], dp[i-1][j-1][0]);
                dp[i][j][2] = val[i][0] + max(dp[i-1][j-1][2], dp[i-1][j-1][0]);
            }
        }
    }
    cout << max(dp[n-1][k][0], max(dp[n-1][k][1], dp[n-1][k][2])) << endl;
}

int main() {
    for (;;)testCase();
    return 0;
}
