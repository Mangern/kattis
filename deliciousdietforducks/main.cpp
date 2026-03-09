#include <bits/stdc++.h>
using namespace std;

const int mxN = 251;

double dp[mxN][mxN][mxN][3];

int main() {
    int a, b, c;
    cin >> a;
    vector<int> sa(a);
    for (auto &x : sa) cin >> x;
    cin >> b;
    vector<int> sb(b);
    for (auto &x : sb) cin >> x;
    cin >> c;
    vector<int> sc(c);
    for (auto &x : sc) cin >> x;

    for (int i = a; i >= 0; --i) {
        for (int j = b; j >= 0; --j) {
            for (int k = c; k >= 0; --k) {
                if (i == a) {
                    dp[i][j][k][0] = 1.0;
                    dp[i][j][k][1] = 0.0;
                    dp[i][j][k][2] = 0.0;
                } else if (j == b) {
                    dp[i][j][k][0] = 0.0;
                    dp[i][j][k][1] = 1.0;
                    dp[i][j][k][2] = 0.0;
                } else if (k == c) {
                    dp[i][j][k][0] = 0.0;
                    dp[i][j][k][1] = 0.0;
                    dp[i][j][k][2] = 1.0;
                } else {
                    double sm = sa[i] + sb[j] + sc[k];
                    double p1 = (double)sa[i] / sm;
                    double p2 = (double)sb[j] / sm;
                    double p3 = (double)sc[k] / sm;
                    dp[i][j][k][0] = p1 * dp[i+1][j][k][0] + p2 * dp[i][j+1][k][0] + p3 * dp[i][j][k+1][0];
                    dp[i][j][k][1] = p1 * dp[i+1][j][k][1] + p2 * dp[i][j+1][k][1] + p3 * dp[i][j][k+1][1];
                    dp[i][j][k][2] = p1 * dp[i+1][j][k][2] + p2 * dp[i][j+1][k][2] + p3 * dp[i][j][k+1][2];
                }
            }
        }
    }

    cout << setprecision(12) << fixed << dp[0][0][0][0] << endl;
    cout << setprecision(12) << fixed << dp[0][0][0][1] << endl;
    cout << setprecision(12) << fixed << dp[0][0][0][2] << endl;
}
