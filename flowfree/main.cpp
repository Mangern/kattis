#include <bits/stdc++.h>
using namespace std;

const int mxN = 16;

vector<int> adj[mxN];
bool vis[mxN];
string flatgrid;

int ipow(int a, int b) {
    if (b == 0) return 1;
    int r = ipow(a, b >> 1);
    r = r * r;
    if (b&1)r = r * a;
    return r;
}

int longest_path(int s, int t) {
    if (s == t) return 0;
    vis[s] = 1;

    int mx = 0;

    for (int v : adj[s]) if (!vis[v]) {
        mx = max(mx, 1 + longest_path(v, t));
    }
    vis[s] = 0;
    return mx;
}

int cid(char c) {
    switch (c) {
        case 'R':
            return 0;
        case 'G':
            return 1;
        case 'B':
            return 2;
        case 'Y':
            return 3;
    }
    return -1;
}

int main() {
    vector<string> grid(4);
    for (auto &s : grid) {
        cin >> s;
    }

    vector<int> idxs;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (grid[i][j] == 'W')idxs.push_back(i * 4 + j);
            flatgrid.push_back(grid[i][j]);
        }
    }

    string cols = "RGBY";
    if (idxs.size() == 10)cols.pop_back();

    vector<vector<int>> ends(cols.size());

    for (int i = 0; i < mxN; ++i) {
        if (cid(flatgrid[i]) == -1) continue;
        ends[cid(flatgrid[i])].push_back(i);
    }

    for (int combo = 0; combo < ipow(cols.size(), idxs.size()); ++combo) {
        int x = combo;
        for (int i : idxs) {
            flatgrid[i] = cols[x%cols.size()];
            x /= cols.size();
        }

        int need[4] = {0,0,0,0};
        for (int i = 0; i < mxN; ++i) {
            adj[i].clear();
            ++need[cid(flatgrid[i])];
        }
        memset(vis, 0, sizeof vis);

        for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j) {
            int u = i * 4 + j;
            if (i>0 && flatgrid[(i-1)*4+j] == flatgrid[u]) {
                adj[(i-1)*4+j].push_back(u);
                adj[u].push_back((i-1)*4+j);
            }
            if (j > 0 && flatgrid[i*4+j-1] == flatgrid[u]) {
                adj[i*4+j-1].push_back(u);
                adj[u].push_back(i*4+j-1);
            }
        }

        bool fail = 0;
        for (int i = 0; i < ends.size(); ++i) {
            if (longest_path(ends[i][0], ends[i][1]) != need[i] - 1) {
                fail = 1;
                break;
            }
        }
        if (!fail) {
            cout << "solvable" << endl;
            return 0;
        }
    }
    cout << "not solvable" << endl;
}
