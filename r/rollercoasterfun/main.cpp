#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 5000;
const int mxT = 25001;

int n;
ll dp[mxN][mxT];
ll w[mxN];
ll t[mxN];
bool spec[mxN];
int ptr = 0;

ll solve(int i, int ti) {
    if (i == 0 || ti == 0)return 0;
    if (dp[i][ti] != -1)return dp[i][ti];

    ll ans = 0;
    if (spec[i-1]) {
        // can take infinitely many

        if (ti >= t[i-1]) {
            ans = max(ans, w[i-1] + solve(i, ti - t[i-1]));
        }
        ans = max(ans, solve(i-1, ti));
    } else {
        if (ti >= t[i-1]) {
            ans = max(ans, w[i-1] + solve(i-1, ti - t[i-1]));
        }
        ans = max(ans, solve(i-1, ti));
    }
    dp[i][ti] = ans;
    return ans;
}

int main() {
    cin >> n;

    for (int i = 0; i < mxN; ++i) for (int j = 0; j < mxT; ++j) {
        dp[i][j] = -1;
    }

    for(int i = 0; i < n; ++i) {
        ll a, b, ti;
        cin >> a >> b >> ti;

        if (b == 0) {
            w[ptr] = a;
            t[ptr] = ti;
            spec[ptr] = 1;
            ++ptr;
            continue;
        }

        for (ll k = 0; a - k * k * b > 0; ++k) {
            w[ptr] = a - k * k * b;
            t[ptr] = ti;
            ++ptr;
        }
    }
    n = ptr;
    assert(ptr < mxN);
    int q;
    cin >> q;

    while (q-->0) {
        int ti;
        cin >> ti;
        cout << solve(n, ti) << endl;
    }
}
