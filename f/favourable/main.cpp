#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
using ll = long long;

ll solve(int u, vector<vector<int>>& adj, vector<ll>& dp, vector<int>& good) {
    if (good[u] == 1) return 1;
    if (good[u] == 2) return 0;

    if (dp[u] != -1) return dp[u];

    dp[u] = 0;

    for (int v : adj[u]) dp[u] += solve(v, adj, dp, good);

    return dp[u];
}

void testCase() {
    int n; cin >> n;

    vector<vector<int>> adj(n, vector<int>());
    vector<int> good(n, 0);

    map<int,int> remap;

    vector<vector<int>> foo(n);

    string s;
    getline(cin,s);
    for (int u = 0; u < n; ++u) {
        getline(cin, s);

        stringstream ss(s);
        int st;
        ss >> st;
        remap[st] = u;

        if (s.back() == 'y') {
            string t;
            ss >> t;

            if (t[0] == 'f') {
                good[u] = 1;
            } else good[u] = 2;
        } else {
            int p1, p2, p3;
            ss >> p1 >> p2 >> p3;
            foo[u].push_back(p1);
            foo[u].push_back(p2);
            foo[u].push_back(p3);
        }
    }

    for (int u = 0; u < n; ++u) {
        for (auto x : foo[u]) {
            adj[u].push_back(remap.at(x));
        }
    }

    vector<ll> dp(n, -1);
    cout << solve(remap[1], adj, dp, good) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-->0)testCase();
}
