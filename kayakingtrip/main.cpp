#include <bits/stdc++.h>
#include <limits>
using namespace std;
using ll = long long;

const ll INF = numeric_limits<ll>::max() / 8;

const int mxN = 35;

ll n;
ll cost[mxN][mxN];
ll dp[mxN];
ll p[mxN];

int main() {
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            cin >> cost[i][j];
        }
    }

    p[0] = -1;
    for (int i = 1; i < n; ++i) {
        dp[i] = INF;

        for (int j = 0; j < i; ++j) {
            if (dp[j] + cost[j][i] < dp[i]) {
                dp[i] = dp[j] + cost[j][i];
                p[i] = j;
            }
        }
    }

    vector<int> path;

    for (int ptr = n - 1; ptr != -1; ptr = p[ptr]) {
        path.push_back(ptr+1);
    }

    reverse(begin(path), end(path));
    for (auto p : path)cout << p << " ";
    cout << endl << dp[n-1] << endl;
}
