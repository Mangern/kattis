#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using G = vector<ii>;

const int INF = 1e5+5;

int min(int a, int b, int c) {
    return min(min(a,b),c);
}

int solve(const G& gr, vector<vector<int>>& dp, int i, int v) {
    if (dp[i][v] != -1) return dp[i][v];
    int &ret = dp[i][v];
    ret = INF;

    if (gr[i].first == -1) {
        // leaf
        if (v == gr[i].second) return ret = 0;
        else return ret;
    }

    int ch1 = 2 * (i + 1) - 1;
    int ch2 = 2 * (i + 1);

    // gate kind, v
    int sols[2][2] = {
        {
            // OR, 0
            solve(gr, dp, ch1, 0) + solve(gr, dp, ch2, 0),
            // OR, 1
            min( 
                solve(gr, dp, ch1, 0) + solve(gr, dp, ch2, 1),
                solve(gr, dp, ch1, 1) + solve(gr, dp, ch2, 0),
                solve(gr, dp, ch1, 1) + solve(gr, dp, ch2, 1)
            )
        },
        {
            // AND, 0
            min( 
                solve(gr, dp, ch1, 0) + solve(gr, dp, ch2, 0),
                solve(gr, dp, ch1, 0) + solve(gr, dp, ch2, 1),
                solve(gr, dp, ch1, 1) + solve(gr, dp, ch2, 0)
            ),
            // AND, 1
            solve(gr, dp, ch1, 1) + solve(gr, dp, ch2, 1)
        }
    };

    if (!gr[i].second) {
        return ret = min(ret, sols[gr[i].first][v]);
    }

    // Can change
    for (int g = 0; g < 2; ++g) {
        ret = min(ret, sols[g][v] + (g != gr[i].first));
    }

    return ret;
}

int main() {
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        int n, v;
        cin >> n >> v;

        G gr;

        vector<vector<int>> dp(n, vector<int>(2, -1));

        for (int i = 0; i < (n - 1)/2; ++i) {
            int g, c;
            cin >> g >> c;
            gr.emplace_back(g,c);
        }
        for (int i = 0; i < (n + 1)/2; ++i) {
            int v;
            cin >> v;
            gr.emplace_back(-1,v);
        }

        int ans = solve(gr, dp, 0, v);

        cout << "Case #" << tc << ": ";
        if (ans == INF) {
            cout << "IMPOSSIBLE\n";
        } else {
            cout << ans << '\n';
        }
    }
}
