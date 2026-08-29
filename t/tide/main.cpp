#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using tup = array<int, 3>;

const double INF = numeric_limits<double>::infinity();

void solve() {
    int H, n, m;
    cin >> H >> n >> m;
    vector<vector<int>> top(n,vector<int>(m)),bot(n,vector<int>(m));

    for (auto &row : top) {
        for (auto &x : row) {
            scanf("%d", &x);
        }
    }
    for (auto &row : bot) {
        for (auto &x : row) {
            scanf("%d", &x);
        }
    }

    // int dist[i][j][h]: time to get to exit from (i, j) with water level h
    // adj[i][j][h] = [{i', j', h'}]
    // Time to move: depends only on h and bot[i][j]
    vector<vector<double>> dist(n, vector<double>(m, INF));
    using state = pair<double, ii>;
    priority_queue<state, vector<state>, greater<state>> pq;
    dist[0][0] = 0.0;
    pq.push({dist[0][0], {0, 0}});

    while (pq.size()) {
        auto [d, p] = pq.top();
        pq.pop();
        auto [i, j] = p;
        if (dist[i][j] < d) continue;

        double curr_h = max(0.0, H - 10.0 * d);
        for (auto [ni, nj] : vector<pair<int,int>>{{i-1,j},{i,j-1},{i+1,j},{i,j+1}}) {
            if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
            if (bot[i][j] > top[ni][nj] - 50) continue;
            if (bot[ni][nj] > top[ni][nj] - 50) continue;
            if (bot[ni][nj] > top[i][j] - 50) continue;
            double h_to_go = min(curr_h, (double)(top[ni][nj] - 50));
            double t_wait = max(0.0, (curr_h - h_to_go)/10.0);
            double nd;
            if (d == 0.0 && t_wait == 0.0) {
                nd = 0.0;
            } else {
                double t_go = h_to_go >= bot[i][j] + 20 ? 1.0 : 10.0;
                nd = d + t_go + t_wait;
            }
            if (nd < dist[ni][nj]) {
                dist[ni][nj] = nd;
                pq.push({nd, {ni, nj}});
            }
        }
    }

    printf("%.8f\n", dist[n-1][m-1]);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; ++tc) {
        printf("Case #%d: ", tc);
        solve();
    }
}
