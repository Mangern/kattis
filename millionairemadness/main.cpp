#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using ii = array<int,3>;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vi> grid(n, vi(m));
    for (auto& v : grid)for (auto& x : v)cin >> x;

    vector<vi> vis(n,vi(m,0));

    priority_queue<ii,vector<ii>,greater<ii>> pq;
    int mx = 0;
    pq.push({0, 0, 0});

    while (pq.size()) {
        auto [cst, i, j] = pq.top();
        pq.pop();

        mx = max(mx, cst);
        if (i == n - 1 && j == m - 1)break;

        if (vis[i][j])continue;

        vis[i][j] = 1;

        for (auto [ni, nj] : vector<array<int,2>>{{i-1,j},{i+1,j},{i,j-1},{i,j+1}}) {
            if (ni < 0 || ni >= n || nj < 0 || nj >= m || vis[ni][nj])continue;
            int dst = max(0, grid[ni][nj] - grid[i][j]);
            pq.push({dst, ni, nj});
        }
    }
    cout << mx << endl;
}
