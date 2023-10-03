#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using tup = tuple<int,int,int>;

const int INF = 1e9;

ll dp[151][101][51];

int f(int C, int n1, int n5, int n10) {
    if (C == 0)return 0;

    int ans = INF;

    if (dp[C][n5][n10] != -1)return dp[C][n5][n10];

    if (n5 == 0 && n10 == 0)return C * 8;



    if (n10 >= 1) {
        ans = min(ans, f(C - 1, n1 + 2, n5, n10 - 1) + 1);
    }

    if (n5 >= 2) {
        ans = min(ans, f(C - 1, n1 + 2, n5 - 2, n10) + 2);
    }

    if (n1 >= 3 && n5 >= 1) {
        ans = min(ans, f(C - 1, n1 - 3, n5 - 1, n10) + 4);
    }

    if (n1 >= 3 && n10 >= 1) {
        ans = min(ans, f(C - 1, n1 - 3, n5 + 1, n10 - 1) + 4);
    }

    dp[C][n5][n10] = ans;
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t-->0) {
        memset(dp, -1, sizeof dp);
        int c, n1, n5, n10;
        cin >> c >> n1 >> n5 >> n10;

        ll ans  = f(c, n1, n5, n10);

        cout << ans << endl;
    }
}
