#include <bits/stdc++.h>
using namespace std;

int main() {
    int t,l,c,w;
    cin >> t >> l >> c >> w;

    vector<vector<int>> dp(l+1, vector<int>(c+1,0));

    vector<int> slot(l+1, 0);
    for (int i = 0; i < t; ++i) {
        int x;
        cin >> x;
        slot[x] = 1;
    }
    for (int i = 1; i <= l; ++i) {
        slot[i] += slot[i-1];
    }

    for (int i = 1; i <= l; ++i) {
        for (int j = 1; j <= c; ++j) {
            dp[i][j] = dp[i-1][j];

            if (i >= w) {
                int take = slot[i] - slot[i-w];
                dp[i][j] = max(dp[i][j], dp[i-w][j-1] + take);
            }
        }
    }
    cout << dp[l][c] << endl;
}
