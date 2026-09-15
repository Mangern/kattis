#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int main() {
    int n, m;
    cin >> n >> m;


    vector<string> grid(n);

    for (int i = 0; i < n; ++i) {
        string& s = grid[i];
        cin >> s;
    }

    for (int si = 0; si < n; ++si) {
        for (int sj = 0; sj < m; ++sj) {
            vector<vector<int>> dist(n, vector<int>(m, -1));
            queue<ii> q;
            dist[si][sj] = 0;
            q.push({si, sj});

            while (q.size()) {
                auto [i, j] = q.front();
                q.pop();

                for (auto [ni, nj] : vector<ii>{{i - 1, j}, {i, j - 1}, {i + 1, j}, {i, j + 1}}) {
                    if (ni < 0 || n <= ni || nj < 0 || m <= nj) continue;

                    if (dist[ni][nj] == -1) {
                        dist[ni][nj] = dist[i][j] + 1;
                        q.push({ni, nj});
                    }
                }
            }

            int mind = 1000, maxd = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (grid[i][j] == '*') {
                        mind = min(mind, dist[i][j]);
                        maxd = max(maxd, dist[i][j]);
                    }
                }
            }

            if (mind == maxd) {
                grid[si][sj] = 'X';
            }
        }
    }

    for (auto row : grid)cout << row << endl;
}
