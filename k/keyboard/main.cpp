#include <bits/stdc++.h>
using namespace std;
using ii = array<int, 2>;
using tup = array<int, 3>;

const int mxN = 51;
const int mxT = 10002;

int n, m;

string grid[mxN];
string target;

// (row, col, target_idx)
int dist[mxN * mxN * mxT];

int getid(int r, int c, int i) {
    return i * m * n + r * m + c;
}

vector<int> adj[mxN * mxN];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    for (int r = 0; r < n; ++r) for (int c = 0; c < m; ++c) {
        int idx = r * m + c;
        for (auto [di, dj] : vector<ii>{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
            int nr = r;
            int nc = c;

            while (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == grid[r][c]) {
                nr += di;
                nc += dj;
            }

            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            adj[idx].push_back(nr * m + nc);
        }
    }

    cin >> target;
    target.push_back('*');

    tup start = {0, 0, 0};
    memset(dist, -1, sizeof dist);
    dist[getid(0,0,0)] = 0;

    queue<tup> q;
    q.push(start);

    while (q.size()) {
        tup u  = q.front();
        auto [r, c, i] = u;
        q.pop();

        int uid = getid(r, c, i);

        if (i == target.length()) {
            cout << dist[uid] << endl;
            break;
        }
        for (int nidx : adj[r * m + c]) {
            int nr = nidx / m;
            int nc = nidx % m;

            tup nxt = {nr, nc, i};
            int nid = getid(nr, nc, i);
            if (dist[nid] == -1) {
                dist[nid] = dist[uid] + 1;
                q.push(nxt);
            }
        }

        if (grid[r][c] == target[i]) {
            tup nxt = {r, c, i + 1};
            int nid = getid(r, c, i + 1);
            if (dist[nid] == -1) {
                dist[nid] = dist[uid] + 1;
                q.push(nxt);
            }
        }
    }

    return 0;
}
