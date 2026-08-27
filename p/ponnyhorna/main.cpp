#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 2e4+4;

int main() {
    ll n;
    cin >> n;

    vector<bool> dp(mxN, false);
    ll sm = 0;
    dp[0] = true;

    for (int i = 0; i < n; ++i) {
        ll s;
        cin >> s;

        sm += s;

        vector<bool> ndp(mxN, false);
        for (ll j = 0; j < mxN; ++j) if (dp[j]) {
            ndp[j+s] = true;
            ndp[abs(j-s)] = true;
        }
        swap(dp, ndp);
    }

    ll delta;
    for (ll i = 0; i < mxN; ++i) {
        if (dp[i]) {
            delta =i ;
            break;
        }
    }

    // (a + b == sm)
    // a + delta == b
    // 2a + delta == sm
    // a = (sm - delta) / 2
    ll a = (sm - delta) / 2;
    ll b = a + delta;
    cout << a * b << endl;
}
