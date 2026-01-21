#include <bits/stdc++.h>
using namespace std;

const int mxN = 1005;

const int INF = 2005;

bool can[mxN][mxN]; // can inst i play note j?


int dp[mxN][mxN]; // min sw. to play the first i notes given that you end with inst. j
int tune[mxN];

int main() {
    int n, m;
    cin >> n >> m;


    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;

        for (int j = 0; j < k; ++j) {
            int u; 
            cin >> u;
            can[i][u] = 1;
        }
    }

    int m1i = 0;
    int m2i = 0;

    for (int i = 0; i <= m; ++i) {
        dp[i][n] = INF;
    }

    for (int i = 1; i <= m; ++i) {
        cin >> tune[i];
        int nm1 = INF;
        int nm1i = n;
        int nm2 = INF;
        int nm2i = n;
        for (int j = 0; j < n; ++j) {
            dp[i][j] = INF;
            if (!can[j][tune[i]]) continue;
            dp[i][j] = dp[i-1][m1i] + (m1i != j);
            dp[i][j] = min(dp[i][j], dp[i-1][m2i] + (m2i != j));

            dp[i][j] = min(dp[i][j], dp[i-1][j]);

            if (dp[i][j] <= nm1) {
                nm2 = nm1;
                nm2i = nm1i;

                nm1 = dp[i][j];
                nm1i = j;
            } else if (dp[i][j] <= nm2) {
                nm2 = dp[i][j];
                nm2i = j;
            }
        }

        m1i = nm1i;
        m2i = nm2i;
    }

    int ans = INF;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, dp[m][i]);
    }
    cout << ans << endl;
}
