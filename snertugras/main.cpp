#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = numeric_limits<ll>::max() / 4;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (auto &s : grid) cin >> s;

    vector<ll> dist(n*m,INF);
    queue<int> q;

    vector<int> goal;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'S') {
                dist[i*m+j] = 0;
                q.push(i*m+j);
            } else if (grid[i][j] == 'G') {
                goal.push_back(i*m+j);
            }
        }
    }

    while (q.size()) {
        int u = q.front();
        q.pop();
        int i = u / m;
        int j = u % m;

        for (auto [ni, nj] : vector<pair<int,int>>{{i-1,j},{i+1,j},{i,j-1},{i,j+1}}) {
            if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
            if (grid[ni][nj] == '#')continue;
            int v = ni * m + nj;
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    ll ans = INF;
    for (int g : goal)ans = min(ans, dist[g]);

    if (ans == INF) cout << "thralatlega nettengdur" << endl;
    else cout << ans << endl;
}
