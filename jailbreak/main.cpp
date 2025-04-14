#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e10;

const int mxN = 101;

string grid[mxN];

int n, m;
ll dist[3][mxN * mxN];

void bfs(int didx, queue<int> q) {
    while (q.size()) {
        int u = q.front();
        q.pop();

        int i = u / m;
        int j = u % m;

        for (auto [ni, nj] : vector<array<int,2>>{{i-1,j},{i+1,j},{i,j-1},{i,j+1}}) {
            if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
            if (grid[ni][nj] == '*') continue;

            int w = (grid[ni][nj] == '#');
            if (dist[didx][ni * m + nj] > dist[didx][u] + w) {
                dist[didx][ni * m + nj] = dist[didx][u] + w;
                q.push(ni * m + nj);
            }
        }
    }
}

void testCase() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    for (int k = 0; k < 3; ++k) {
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
            dist[k][i*m+j] = INF;
        }
    }

    queue<int> q1, q2, q3;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] != '*' && (i == 0 || j == 0 || i == n - 1 || j == m-1)) {
                q1.push(i * m + j);
                dist[0][i*m+j] = (grid[i][j] == '#');
            }
            if (grid[i][j] == '$') {
                if (q2.empty()) {
                    dist[1][i*m+j] = 0;
                    q2.push(i*m+j);
                } else {
                    dist[2][i*m+j] = 0;
                    q3.push(i*m+j);
                }
            }
        }
    }

    bfs(0, q1);
    bfs(1, q2);
    bfs(2, q3);

    ll mind = INF;

    for (int u = 0; u < n * m; ++u) {
        mind = min(mind, dist[0][u] + dist[1][u] + dist[2][u] - 2*(grid[u/m][u%m] == '#'));
    }
    cout << mind << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-->0)testCase();
}
