#include <iostream>
#include <string>
using namespace std;
using ll = long long;
const ll INF = 1e9;

const int mxN = 201;

int n;
string s;
ll dp[mxN][mxN];

int main() {
    cin >> s;
    n = s.length();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)dp[i][j] = INF;
    }

    for (int i = n - 1; i >= 0; --i) {
        for (int j = i; j < n; ++j) {
            if (i == j) {
                dp[i][j] = 1;
                continue;
            }
            // concatenation
            for (int k = i+1; k <= j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k-1] + dp[k][j]);
            }
            int len = j - i + 1;
            // repetition
            // x x x x x x x x
            //       i
            //             k
            for (int l = 1; 2 * l <= len; ++l) if (len % l == 0) {
                bool rep = 1;
                for (int k = i+l; k <= j; ++k) {
                    if (s[k] != s[(k - i)%l+i]) {
                        rep = 0;
                        break;
                    }
                }
                if (rep) {
                    dp[i][j] = min(dp[i][j], dp[i][i+l-1]);
                }
            }
        }
    }
    cout << dp[0][n-1] << endl;
}
