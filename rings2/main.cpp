#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; ++i)cin >> grid[i];

    vector<vector<int>> vis(n, vector<int>(m, 0));

    queue<pair<int,int>> q;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '.')continue;

            if (i == 0 || grid[i-1][j] == '.') {
                vis[i][j] = 1;
                q.push({i, j});
            }
            if (i == n - 1 || grid[i+1][j] == '.') {
                vis[i][j] = 1;
                q.push({i, j});
            }
            if (j == 0 || grid[i][j-1] == '.') {
                vis[i][j] = 1;
                q.push({i, j});
            }
            if (j == m - 1 || grid[i][j+1] == '.') {
                vis[i][j] = 1;
                q.push({i, j});
            }
        }
    }

    int mx = 0;
    while (q.size()) {
        auto [i, j] = q.front();
        q.pop();
        mx = max(mx, vis[i][j]);

        if (i > 0 && grid[i-1][j] != '.' && !vis[i-1][j]) {
            vis[i-1][j] = vis[i][j] + 1;
            q.push({i - 1, j});
        }
        if (i < n - 1 && grid[i+1][j] != '.' && !vis[i+1][j]) {
            vis[i+1][j] = vis[i][j] + 1;
            q.push({i + 1, j});
        }
        if (j > 0 && grid[i][j-1] != '.' && !vis[i][j-1]) {
            vis[i][j-1] = vis[i][j] + 1;
            q.push({i, j - 1});
        }
        if (j < m - 1 && grid[i][j+1] != '.' && !vis[i][j+1]) {
            vis[i][j+1] = vis[i][j] + 1;
            q.push({i, j + 1});
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mx >= 10)cout << ".";

            if (!vis[i][j]) {
                cout << "..";
            } else if (vis[i][j] < 10) {
                cout << "." << vis[i][j];
            } else {
                cout << vis[i][j];
            }
        }
        cout << endl;
    }
}
