#include <bits/stdc++.h>
using namespace std;
using ii = array<int,2>;
using vi = vector<int>;

const int mxN = 1006;
const int INF = 1e7;

int n, m;

char grid[mxN][mxN];

ii dir[8] = {
    {-1,  0},
    {-1,  1},
    { 0,  1},
    { 1,  1},
    { 1,  0},
    { 1, -1},
    { 0, -1},
    {-1, -1}
};

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    int q;
    cin >> q;

    while (q-->0) {
        ii start;
        ii goal;

        vector<vi> dist(n, vi(m, INF));
        cin >> start[0] >> start[1], --start[0], --start[1];
        cin >> goal[0] >> goal[1], --goal[0], --goal[1];

        dist[start[0]][start[1]] = 0;
        queue<ii> q;
        q.push(start);
        while (q.size()) {
            vector<ii> nq;

            int cur = dist[q.front()[0]][q.front()[1]];

            while (q.size()) {
                auto [i, j] = q.front();
                q.pop();

                for (int k = 0; k < 8; ++k) {
                    auto [di, dj] = dir[k];
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                    if ((int)(grid[i][j]-'0') == k) {
                        if (dist[ni][nj] > cur) {
                            dist[ni][nj] = cur;
                            q.push({ni,nj});
                        }
                    } else {
                        if (dist[ni][nj] > cur + 1) {
                            dist[ni][nj] = cur + 1;
                            nq.push_back({ni,nj});
                        }
                    }
                }
            }

            for (auto [i, j] : nq) {
                if (dist[i][j] < cur + 1)continue;
                q.push({i, j});
            }
        }
        cout << dist[goal[0]][goal[1]] << endl;
    }

    return 0;
}
