#include <bits/stdc++.h>
#include <string>
using namespace std;
using ll = long long;
using ii = pair<ll, ll>;

const int mxN = 16;

ii dp[mxN][2];

string s;

ii solve(int i, int touching) {

    if (i >= s.length()) {
        return {0, 1};
    }

    if (dp[i][touching].first != -1) {
        return dp[i][touching];
    }

    int stop  = touching ? s[i] - '0' : 9;

    ll dsum = 0;
    ll cnt = 0;
    for (int d = 0; d <= stop; ++d) {
        auto [pdsum, pcnt] = solve(i + 1, touching && d == stop);
        dsum += pdsum + d * pcnt;
        cnt += pcnt;
    }
    return dp[i][touching] = {dsum, cnt};
}

ll count_leq(ll x) {
    s = to_string(x);
    for (int i = 0; i < mxN; ++i) {
        dp[i][0] = dp[i][1] = {-1,-1};
    }
    return solve(0, 1).first;
}

int main() {
    int T;
    cin >> T;
    while (T-->0) {
        ll a, b;
        cin >> a >> b;

        ll ans = count_leq(b);
        if (a > 0) ans -= count_leq(a-1);
        cout << ans <<'\n';
    }
}
