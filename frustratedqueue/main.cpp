#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1000000;
const int mxN = 1001;

int n;
ll dp[mxN][mxN];
string s;

int main() {
    while (getline(cin, s)) {
        n = s.length();
        int n5 = 0, n10 = 0;

        for (char c : s) {
            if (c == '(') {
                ++n5;
            } else if (c == ')') {
                ++n10;
            }
        }

        if (s[0] == ')') {
            cout << 0 << endl;
            continue;
        }


        int rem5 = n / 2;
        for (int i = 0; i < n; ++i) {
            for (int r = 0; r <= min(i+1, rem5); ++r) {
                dp[i][r] = 0;
            }
        }

        dp[0][0] = 0;
        dp[0][1] = 1;
        for (int i = 1; i < n; ++i) {
            for (int r = 0; r <= min(i+1,rem5); ++r) {
                // number of ways to reorder ..i with r 5-coin ppl to distribute
                if (s[i] == '(') {
                    // must spend a fucker
                    if (r == 0) {
                        // impossible
                        dp[i][r] = 0;
                    } else {
                        dp[i][r] = dp[i-1][r-1];
                    }
                } else if (s[i] == ')') {
                    // cannot spend a fucker
                    int n10 = i+1-r;
                    if (r<=n10-1) {
                        dp[i][r] = 0;
                    } else {
                        dp[i][r] = dp[i-1][r];
                    }
                } else {
                    int n10 = i+1-r;
                    if (r<=n10-1) {
                        dp[i][r] = 0;
                    } else {
                        dp[i][r] = dp[i-1][r];
                    }

                    if (r>0) {
                        dp[i][r] += dp[i-1][r-1];
                        dp[i][r] %= MOD;
                    }
                }
            }
        }

        cout << dp[n-1][rem5] << endl;
    }
}
