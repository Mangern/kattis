#include <bits/stdc++.h>
using namespace std;

const int mxN = 55;

int flood[mxN][mxN];
int dist[mxN][mxN];

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    queue<int> flqueue;
    queue<int> q;
    int fini, finj;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];

        memset(flood[i], -1, sizeof flood[i]);
        memset(dist[i], -1, sizeof dist[i]);
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '*') {
                flood[i][j] = 0;
                flqueue.push(i * m + j);
            }
            if (grid[i][j] == 'S') {
                dist[i][j] = 0;
                q.push(i * m + j);
            }
            if (grid[i][j] == 'D') {
                fini = i;
                finj = j;
            }
        }
    }

    while (flqueue.size()) {
        int u = flqueue.front();
        flqueue.pop();
        int i = u / m;
        int j = u % m;

        for (auto [ni, nj] : vector<pair<int,int>>{{i-1,j},{i+1,j},{i,j-1},{i,j+1}}) {
            if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
            if (flood[ni][nj] != -1) continue;
            if (grid[ni][nj] != '.') continue;
            flood[ni][nj] = flood[i][j] + 1;
            flqueue.push(ni * m + nj);
        }
    }

    while (q.size()) {
        int u = q.front();
        q.pop();
        int i = u / m;
        int j = u % m;
        int nd = dist[i][j] + 1;
        for (auto [ni, nj] : vector<pair<int,int>>{{i-1,j},{i+1,j},{i,j-1},{i,j+1}}) {
            if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
            if (dist[ni][nj] != -1) continue;
            if (flood[ni][nj] >= 0 && flood[ni][nj] <= nd) continue;
            if (grid[ni][nj] == 'X') continue;
            dist[ni][nj] = nd;
            q.push(ni * m + nj);
        }
    }

    if (dist[fini][finj] == -1) cout << "KAKTUS" << endl;
    else cout << dist[fini][finj] << endl;

}
