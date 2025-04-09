#include <bits/stdc++.h>
#include <cstring>
using namespace std;
using ll = long long;

const int mxX = 805;
const int mxN = 41;

// i,x,y
ll n;
ll dp[mxX][mxX];
ll dp2[mxX][mxX];
const ll OFF = 402;

int main() {
    cin >> n;

    dp[OFF][OFF] = 1;
    ll dx,dy;
    for (int i = 0; i < n; ++i) {
        cin >> dx >> dy;

        for (int j = 0; j < mxX; ++j) {
            memcpy(dp2[j], dp[j], mxX * sizeof(ll));
        }

        for (ll x = -400; x <= 400; ++x) {
            for (ll y = -400; y <= 400; ++y) {
                if (OFF + x + dx < 0 || OFF + x + dx >= mxX) continue;
                if (OFF + y + dy < 0 || OFF + y + dy >= mxX) continue;

                dp2[OFF+x+dx][OFF+y+dy] += dp[OFF+x][OFF+y];
            }
        }

        for (int j = 0; j < mxX; ++j) {
            memcpy(dp[j], dp2[j], mxX * sizeof(ll));
        }
    }
    cout << dp[OFF][OFF] - 1 << endl;
}
