#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> m >> n;

    vector<string> grid(n);

    for (auto &s : grid) cin >> s;

    priority_queue<tuple<int, int, int>> q;

    const int INF = 100000;

    vector<vector<int>> dist(n, vector<int>(m, INF));
    vector<pair<int, int>> exits;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '*') {
                q.push({0, i, j});
                dist[i][j] = 0;
            }

            if (grid[i][j] == 'E') {
                exits.push_back({i, j});
            }
        }
    }


    while (q.size()) {
        auto [d, i, j] = q.top();
        q.pop();
        if (dist[i][j] < -d) continue;

        for (auto [ni, nj] : vector<pair<int, int>>{{i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}}) {
            if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
            if (grid[ni][nj] == '#') continue;

            int w = 0;
            if (grid[ni][nj] == 'D')w = 1;

            if (dist[ni][nj] > dist[i][j] + w) {
                dist[ni][nj] = dist[i][j] + w;
                q.push({-dist[ni][nj], ni, nj});
            }
        }
    }

    int ans = INF;
    for (auto [ei, ej] : exits) {
        ans = min(ans, dist[ei][ej]);
    }

    if (ans >= INF) {
        cout << "NOT POSSIBLE" << endl;
    } else {
        cout << ans << endl;
    }
}
