#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll, 2>;

const int mxN = 130;

ll dp[mxN][mxN];

int main() {
    ll xi, yi, xf, yf, x1, y1, x2, y2;
    cin >> xi >> yi >> xf >> yf >> x1 >> y1 >> x2 >> y2;

    dp[xi][yi] = 1;

    for (ll i = 0; i < mxN; ++i) {
        for (ll j = 0; j < mxN; ++j) {
            if (ii{i,j} == ii{x1,y1}) continue;
            if (ii{i,j} == ii{x2,y2}) continue;
            if (i > 0)dp[i][j] += dp[i-1][j];
            if (j > 0)dp[i][j] += dp[i][j-1];
        }
    }
    cout << dp[xf][yf] << endl;
}
