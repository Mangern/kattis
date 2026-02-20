#include <bits/stdc++.h>
using namespace std;

const int mxN = 2 * 500 * 500 + 10;

int n, m;
// [0, n * m) : next move has to increase
// [n*m, 2 * n * m): next move has to 
int alt[505][505];
vector<int> adj[mxN];
int dist[mxN];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> alt[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int di = -1; di <= 1; ++di) {
                for (int dj = -1; dj <= 1; ++dj) if (di != 0 || dj != 0) {
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;

                    if (alt[ni][nj] > alt[i][j]) {
                        // this move increases, next has to decrease
                        adj[i * m + j].push_back(ni * m + nj + n * m);
                    } else if (alt[ni][nj] < alt[i][j]) {
                        // this move decreases, next has to increase
                        adj[i * m + j + n * m].push_back(ni * m + nj);
                    }
                }
            }
        }
    }

    int is, js, it, jt;
    cin >> is >> js >> it >> jt, --is, --js, --it, --jt;
    memset(dist, -1, sizeof dist);
    queue<int> q;
    dist[is * m + js] = 0;
    dist[is * m + js + n * m] = 0;
    q.push(is * m + js);
    q.push(is * m + js + n * m);

    while (q.size()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    int f1 = dist[it * m + jt];
    int f2 = dist[it * m + jt + n * m];

    if (f1 == -1) cout << f2 << endl;
    else if (f2 == -1) cout << f1 << endl;
    else cout << min(f1, f2) << endl;
}
