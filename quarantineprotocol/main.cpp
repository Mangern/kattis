#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;

            grid[i].push_back(c);
        }
    }

    int infected = 0;

    for (int col = 0; col < m; ++col) {
        queue<int> q;

        vector<int> vis(n, 0);

        for (int i = 0; i < n; ++i) {
            if (grid[i][col] == 'X') {
                vis[i] = 1;
                q.push(i);
            }
        }

        while (q.size()) {
            int i = q.front();
            q.pop();

            if (i > 0 && grid[i-1][col] != '#' && !vis[i-1]) {
                vis[i-1] = 1;
                q.push(i-1);
            }
            if (i + 1 < n && grid[i+1][col] != '#' && !vis[i+1]) {
                vis[i+1] = 1;
                q.push(i+1);
            }
        }

        infected += accumulate(begin(vis), end(vis), 0);
    }

    cout << n * m - infected << endl;
}
