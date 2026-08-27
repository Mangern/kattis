#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e3+5;

string grid[mxN];

int n, m;
bool vis[mxN][mxN];

int main() {
    cin >> n >> m;
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];

        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'S') {
                vis[i][j] = 1;
                q.push(i * m + j);
            }
        }
    }

    while (q.size()) {
        int i = q.front() / m;
        int j = q.front() % m;
        q.pop();

        for (auto [ni, nj] : vector<pair<int, int>>{{i-1, j}, {i+1,j},{i,j-1},{i,j+1}}) {
            if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
            if (grid[ni][nj] == '#') continue;
            if (vis[ni][nj]) continue;
            vis[ni][nj] = 1;
            q.push(ni * m + nj);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'P') {
                ans += vis[i][j];
            }
        }
    }
    cout << ans << endl;
}
