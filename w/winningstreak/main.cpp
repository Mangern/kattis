#include <bits/stdc++.h>
using namespace std;
using ld = long double;

const int mxN = 3003;

ld p_leq[mxN][mxN]; // for each season length i, probability that no winning streak is longer than j
ld ppow[mxN];                
int n;
ld p;

int main() {
    while (cin >> n) {
        cin >> p;

        ppow[0] = 1.0;
        for (int i = 1; i <= n; ++i) {
            ppow[i] = ppow[i-1] * p;
        }

        for (int i = 0; i <= n; ++i) {
            for (int s = 0; s <= n; ++s) {
                if (s >= i)p_leq[i][s] = 1.0;
                else if (i - s == 1) {
                    // only way to exceed s is if all i matches are wins
                    p_leq[i][s] = 1.0 - ppow[i];
                } else {
                    // probability that no exceed s given 1 fewer match minus
                    // the only way that *this* match can make us exceed the limit
                    // which is (i-s-2) L WWW..W (s+1 times)
                    p_leq[i][s] = p_leq[i-1][s] - p_leq[i - s - 2][s] * (1 - p) * ppow[s+1];
                }
            }
        }

        ld ans = 0.0;

        for (int i = 1; i <= n; ++i) {
            ans += (ld)i * (p_leq[n][i] - p_leq[n][i-1]);
        }
        cout << setprecision(8) << fixed << ans << endl;
    }
}
