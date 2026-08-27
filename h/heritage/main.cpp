#include <iostream>
#include <string>
#include <cstring>
using namespace std;
using ll = long long;

const ll MOD = 1e9+7;

const int mxN = 1005;

int n, m;
string goal;
string d[mxN];
ll a[mxN];

ll dp[33];

ll solve(int p) {
    if (p == m) return 1;
    if (p > m) return 0;

    if (dp[p] != -1) return dp[p];
    ll& ret = dp[p];

    ret = 0;

    for (int i = 0; i < n; ++i) {
        if (goal.substr(p, d[i].length()) == d[i]) {
            ll s = (a[i] * solve(p + d[i].length()))%MOD;
            ret = (ret + s) % MOD;
        }
    }

    return ret;
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> n >> goal;
    m = goal.length();

    for (int i = 0; i < n; ++i) {
        cin >> d[i] >> a[i];
    }
    cout << solve(0) << endl;
}
