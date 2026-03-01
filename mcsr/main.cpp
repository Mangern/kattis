#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 2e5+5;

ll n, s;
ll rep[mxN]; // time to repair
ll pos[mxN]; // nether location
ll dp[mxN][2]; // time to reach end starting at position i, 0/1: overworld/nether
               // i == 0: start

int main() {
    cin >> n >> s;

    for (ll i = 1; i <= n; ++i) {
        cin >> pos[i] >> rep[i];
    }

    dp[n][0] = s - 8 * pos[n];
    dp[n][1] = rep[n] + dp[n][0];

    for (ll i = n - 1; i >= 1; --i) {
        // if at overworld:
        // either go straight to next:
        dp[i][0] = 8 * (pos[i+1]-pos[i]) + dp[i+1][0];
        // or switch to nether and go to next
        dp[i][0] = min(dp[i][0], rep[i] + pos[i+1] - pos[i] + dp[i+1][1]);

        // if at nether
        // either go straight to next
        dp[i][1] = pos[i+1] - pos[i] + dp[i+1][1];
        // or switch to overworld
        dp[i][1] = min(dp[i][1], rep[i] + 8 * (pos[i+1] - pos[i]) + dp[i+1][0]);
    }

    cout << 8 * pos[1] + dp[1][0] << endl;
}
