#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e4+4;

array<int, 9> vals = {1, 2, 5, 10, 20, 50, 100, 200, 500};

bool splittable(int s, array<int, 9> ncoins) {
    if (s % 2 != 0) return false;
    vector<int> coins;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < ncoins[i]; ++j)coins.push_back(vals[i]);
    }
    int n = coins.size();

    // dp[i]: Considering first i coins, which sums can be made?
    vector<bitset<mxN>> dp(n+1);
    dp[0].set(0);
    for (int i = 1; i <= n; ++i) {
        // Can make all from previous
        dp[i] = dp[i-1];
        // Can also increase all from previous by this coin
        dp[i] |= (dp[i-1] << coins[i-1]);
    }
    return dp[n].test(s/2);
}

int main() {
    int n;
    cin >> n;

    for (int n1 = 0; n1 <= 1; ++n1) {
        for (int n2 = 0; n2 < 5; ++n2) {
            if (n1 + 2 * n2 > n) break;
            for (int n5 = 0; n5 <= 1; ++n5) {
                if (n1 + 2 * n2 + 5 * n5 > n) break;
                for (int n10 = 0; n10 <= 1; ++n10) {
                    for (int n20 = 0; n20 < 5; ++n20) {
                        int v1 = n1 + 2 * n2 + 5 * n5 + 10 * n10 + 20 * n20;
                        if (v1 > n) break;
                        for (int n50 = 0; n50 <= 1; ++n50) {
                            int v2 = v1 + 50 * n50;
                            if (v2 > n) break;
                            for (int n100 = 0; n100 <= 1; ++n100) {
                                int v3 = v2 + 100 * n100;
                                for (int n200 = 0; v3 + 200 * n200 <= n; ++n200) {
                                    int rem = n - (v3 + 200 * n200);
                                    if (rem % 500 != 0) continue;
                                    int n500 = rem / 500;
                                    array<int, 9> coins = {n1, n2, n5, n10, n20, n50, n100, n200, n500};
                                    if (!splittable(n, coins)) {
                                        vector<int> ret;
                                        for (int i = 0; i < 9; ++i) {
                                            for (int j = 0; j < coins[i]; ++j) {
                                                ret.push_back(vals[i]);
                                            }
                                        }
                                        cout << ret.size() << endl;
                                        for (auto x : ret) cout << x << " ";
                                        cout << endl;
                                        return 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "splittable" << endl;
}
