#include <bits/stdc++.h>
using namespace std;
using tup = array<int,3>;

const int mxN = 35;

const int INF = 100000;

int n, m, o;
char grid[mxN][mxN][mxN];
int dist[mxN][mxN][mxN];

int main() {
    for (;;) {
        cin >> n >> m >> o;

        if (!n) break;

        queue<tup> q;
        tup goal;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < o; ++k) {
                    char &c = grid[i][j][k];
                    cin >> c;

                    dist[i][j][k] = INF;
                    if (c == 'S') {
                        dist[i][j][k] = 0;
                        q.push({i,j,k});
                    } else if (c == 'E') {
                        goal = {i, j, k};
                    }
                }
            }
        }
        while (q.size()) {
            auto [i, j, k] = q.front();
            q.pop();

            for (auto [ni, nj, nk] : vector<tup>{
                {i-1, j, k},
                {i+1, j, k},
                {i, j-1, k},
                {i, j+1, k},
                {i, j, k-1},
                {i, j, k+1}}) 
            {
                if (ni < 0 || ni >= n || nj < 0 || nj >= m || nk < 0 || nk >= o) continue;
                if (grid[ni][nj][nk] == '#') continue;
                if (dist[i][j][k] + 1 < dist[ni][nj][nk]) {
                    dist[ni][nj][nk] = dist[i][j][k] + 1;
                    q.push({ni, nj, nk});
                }
            }
        }

        auto [gi, gj, gk] = goal;
        if (dist[gi][gj][gk] == INF) {
            cout << "Trapped!" << endl;
        } else {
            cout << "Escaped in " << dist[gi][gj][gk] << " minute(s)." << endl;
        }
    }
}
