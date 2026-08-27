#include <bits/stdc++.h>
using namespace std;

using tup = array<int, 4>;

int n, m;

int back(int dir) {
    if (dir == 0) return 0;
    if (dir == 1) return 2;
    if (dir == 2) return 1;
    if (dir == 3) return 4;
    if (dir == 4) return 3;
    assert(false);
}

int dist[1001 * 1001 * 5 * 3];

int getid(int r, int c, int dir, int steps) {
    return steps * 1001 * 1001 * 5 + dir * 1001 * 1001 + 1001 * r + c;
}

void testCase() {
    cin >> n >> m;
    vector<string> grid(n);

    for (auto& s : grid)cin >> s;

    int si, sj;
    int ti, tj;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 'R') {
            si = i, sj = j;
        }
        if (grid[i][j] == 'D') {
            ti = i, tj = j;
        }
    }

    // (r, c, dir, steps)
    // dir: 0 (none), 1, 2, 3, 4
    // 1000 * 1000 * 5 * 3
    memset(dist, -1, sizeof dist);
    tup start = {si, sj, 0, 0};
    dist[getid(si, sj, 0, 0)] = 0;

    queue<tup> q;
    q.push(start);

    while (q.size()) {
        tup u = q.front();
        q.pop();
        auto [r, c, dir, steps] = u;
        int uid = getid(r, c, dir, steps);

        if (r == ti && c == tj) {
            cout << dist[uid] << endl;
            return;
        }

        int ndir = 0;

        for (auto [di, dj] : vector<array<int,2>>{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
            ++ndir;
            int nr = r + di;
            int nc = c + dj;
            if (nr <  0 || nr >= n || nc < 0 || nc >= m) continue;
            if (grid[nr][nc] == 'B') continue;

            if (steps == 2 && ndir == dir) continue;

            if (ndir == back(dir)) continue;

            int nsteps = 0;
            if (ndir == dir)nsteps = steps + 1;
            else nsteps = 1;

            tup nxt = {nr, nc, ndir, nsteps};
            int nid = getid(nr, nc, ndir, nsteps);
            if (dist[nid] != -1)continue;
            dist[nid] = dist[uid] + 1;
            q.push(nxt);
        }
    }
    cout << -1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-->0)testCase();
    return 0;
}
