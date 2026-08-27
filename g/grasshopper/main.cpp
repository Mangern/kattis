#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ii = array<int, 2>;
using vi = vector<int>;

const int INF = 1e8;

ii dir[8] = {
    {-2,  1},
    {-1,  2},
    { 1,  2},
    { 2,  1},
    { 2, -1},
    { 1, -2},
    {-1, -2},
    {-2, -1}
};

int main() {
    int n, m, si, sj, ti, tj;

    while (cin >> n) {
        cin >> m >> si >> sj >> ti >> tj;
        -- si, --sj, --ti, --tj;

        vector<vi> dist(n, vi(m, INF));

        dist[si][sj] = 0;
        queue<ii> q;
        q.push({si,sj});

        while (q.size()) {
            auto [i, j] = q.front();
            q.pop();
            for (int k = 0; k < 8; ++k) {
                auto [di, dj] = dir[k];
                int ni = i+di;
                int nj = j+dj;
                if (ni < 0 || ni >= n || nj < 0 || nj >= m)continue;
                if (dist[i][j] + 1 < dist[ni][nj]) {
                    dist[ni][nj] = dist[i][j] + 1;
                    q.push({ni, nj});
                }
            }
        }
        cout << (dist[ti][tj] == INF ? "impossible" : to_string(dist[ti][tj])) << endl;

    }
}
