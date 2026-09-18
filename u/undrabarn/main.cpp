#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 20;

int n;
string s;
ll dp[mxN][2][2];

ll solve(int i, int touching, int lz_allowed) {
    if (i >= n) {
        if (lz_allowed) return 0;
        return 1;
    }

    ll &r = dp[i][touching][lz_allowed];
    if (r != -1) {
        return r;
    }
    r = 0;
    for (char c = '0'; (touching ? (c <= s[i]) : (c <= '9')); ++c) {
        if (c == '0' && !lz_allowed) continue;
        if (c == '8') continue;
        int ntouching;
        if (touching > 0 && c == s[i])ntouching = 1;
        else ntouching = 0;
        r += solve(i + 1, ntouching, c == '0' && lz_allowed);
    }
    return r;
}

// How many numbers less than or equal to x
// contain neither 0 nor 8
ll cnt(ll x) {
    s = to_string(x);
    n = s.length();
    for (int i = 0; i < n; ++i) {
        dp[i][0][0] = dp[i][0][1] = -1;
        dp[i][1][0] = dp[i][1][1] = -1;
    }
    return solve(0, 1, 1);
}

int main() {
    ll k;
    cin >> k;
    ll lo = 1;
    ll hi = 1e18;

    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        ll c = cnt(mid);

        if (c >= k) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    cout << lo << endl;
}
