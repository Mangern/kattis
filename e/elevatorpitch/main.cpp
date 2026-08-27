#include <bits/stdc++.h>
using namespace std;

const int mxN = 505;

int n, m;
int grid[mxN * mxN];
bool vis[mxN * mxN];

void bfs(int u) {
    int i = u / m;
    int j = u % m;

    for (auto [ni, nj] : vector<array<int,2>>{{i-1,j},{i+1,j},{i,j-1},{i,j+1}}) {
        if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
        if (vis[ni * m + nj]) continue;
        if (grid[ni * m + nj] > grid[u]) continue;
        if (grid[ni * m + nj] <= 1) continue;
        vis[ni * m + nj] = 1;
        bfs(ni * m + nj);
    }
}

int main() {
    cin >> n >> m;

    vector<int> que;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int a;
            cin >> a;
            que.push_back(i * m + j);
            grid[i * m + j] = a;
        }
    }

    sort(rbegin(que), rend(que), [&](int u, int v) { return grid[u] < grid[v]; });
    int ans = 0;
    for (int u : que) if (!vis[u]) {
        if (grid[u] <= 1) break;
        ++ans;
        vis[u] = 1;
        bfs(u);
    }
    cout << ans << endl;
}
