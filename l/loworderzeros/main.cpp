#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 1e6+4;

ll dp[mxN];

int main() {
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 6;

    for (ll i = 4; i < mxN; ++i) {
        ll& x = dp[i];
        x = dp[i-1] * i;
        while (x % 10 == 0)x /= 10;
        x %= 1000000;
    }

    while (true) {
        int i;
        cin >> i;
        if (!i) break;
        cout << dp[i]%10 << endl;
    }
}
