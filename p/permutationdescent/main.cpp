#include <bits/stdc++.h>
using namespace std;
using ll = long long;


const int N = 105;
const ll MOD = 1001113;


ll dp[N][N];
ll ncr[N][N];

ll nCr(ll n, ll k) {
    if (k > n || k < 0)return 0;
    return ncr[n][k];
}


ll pdc(ll n, ll v) {
    if (v == 0)return 1;
    if (v >= n)return 0;
    if (v < 0)return 0;

    if (dp[n][v] != -1)return dp[n][v];

    ll ans = pdc(n-1,v) % MOD;

    for (ll i = 1; i < n; ++i) {
        for (ll vi = 0; vi < v; ++vi) {
            ll curr = nCr(n-1,i) * pdc(i, vi) % MOD;
            curr = (curr * pdc(n-i-1,v-vi-1))%MOD;
            ans += curr;
            if (ans >= MOD)ans -= MOD;
        }
    }
    dp[n][v] = ans;
    return ans;
}

int main() {
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j)dp[i][j] = -1;

    ncr[0][0] = 1;

    for (int i = 1; i < N; ++i) for (int j = 0; j <= i; ++j) {
        ncr[i][j] = nCr(i-1,j-1) + nCr(i-1,j);
        if (ncr[i][j] >= MOD)ncr[i][j] -= MOD;
    }

    int t;
    cin >> t;
    while (t-->0) {
        int k,n,v;
        cin >> k >> n >> v;
        cout << k << " " << pdc(n,v) << endl;
    }
    return 0;
}
