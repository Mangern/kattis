#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000;

int daym[24];

int dp[25][25][1<<8];

int main() {
    for (int i = 0; i < 7; ++i) {
        string s;
        cin >> s;

        for (int j = 0; j < 24; ++j) {
            if (s[j] == '.') {
                daym[j] |= (1<<i);
            }
        }
    }

    int d, h;
    cin >> d >> h;

    for (int i = 0; i < (1<<7); ++i) {
        for (int j = 0; j <= 24; ++j) {
            dp[0][j][i] = -INF;
        }
    }

    for (int dmask = 0; dmask < (1<<7); ++dmask) {
        if (__builtin_popcount(dmask) < d) {
            continue;
        }
        dp[0][0][dmask] = 0; // use all hrs
    }

    for (int i = 1; i <= 24; ++i) {
        for (int hleft = 0; hleft <= 24; ++hleft) {
            for (int dmask = 0; dmask < (1<<7); ++dmask) {
                int &r = dp[i][hleft][dmask];
                 r = -INF;
                if (__builtin_popcount(dmask) < d) {
                    continue;
                }

                // don't pick this day
                r = dp[i-1][hleft][dmask];

                if (hleft > 0) {
                    int gain = __builtin_popcount(dmask & daym[i-1]);
                    r = max(r, dp[i-1][hleft-1][dmask] + gain);
                }
            }
        }
    }

    double ans = -numeric_limits<double>::infinity();

    for (int dmask = 0; dmask < (1<<7); ++dmask) {
        for (int hstart = h; hstart <= 24; ++hstart) {
            double tot = __builtin_popcount(dmask) * hstart;
            double get = dp[24][hstart][dmask];
            ans = max(ans, get / tot);
        }
    }
    cout << setprecision(10) << fixed << ans << endl;
}
