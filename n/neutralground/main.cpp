#include <bits/stdc++.h>
using namespace std;

const int mxH = 41;
const int mxN = 2 * 41 * 41 + 10;

int h, w;
int s, t;
string grid[mxH];

vector<int> adj[mxN];
int flo[mxN][mxN];
int par[mxN];
bool vis[mxN];
 
bool bfs() {
    memset(vis, 0, sizeof vis);
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if ((!flo[u][v]) || vis[v])continue;
            q.push(v);
            par[v] = u;
            vis[v] = 1;
        }
    }
    return vis[t];
}
 
int maxFlow() {
    int ans = 0;
    while (bfs()) {
        int curr = mxN * 9;
        for (int v = t; v != s; v = par[v]) {
            int u = par[v];
            curr = min(curr, flo[u][v]);
        }
        ans += curr;
        for (int v  = t; v != s; v = par[v]) {
            int u = par[v];
            flo[u][v] -= curr;
            flo[v][u] += curr;
        }
    }
    return ans;
}

int main() {
    cin >> w >> h;

    for (int i = 0; i < h; ++i) {
        cin >> grid[i];
    }

    int big = mxN * 9;

    s = 0;
    t = 2 * h * w + 3;

    auto add_edge = [&](int u, int v, int c) {
        flo[u][v] = c;
        adj[u].push_back(v);
        adj[v].push_back(u);
    };

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] == '0') continue;

            int u_in = 2 * (i * w + j) + 1;
            int u_out = 2 * (i * w + j) + 2;

            if (grid[i][j] == 'A') {
                add_edge(s, u_in, big);
                add_edge(u_in, u_out, big);
            } else if (grid[i][j] == 'B') {
                add_edge(u_out, t, big);
                add_edge(u_in, u_out, big);
            } else {
                int c = grid[i][j] - '0';
                add_edge(u_in, u_out, c);
            }
            for (auto [ni, nj] : vector<pair<int, int>>{{i-1,j},{i,j-1},{i+1,j},{i,j+1}}) {
                if (ni < 0 || h <= ni || nj < 0 || w <= nj) continue;
                if (grid[ni][nj] == '0') continue;

                int v_in = 2 * (ni * w + nj) + 1;
                add_edge(u_out, v_in, big);
            }
        }
    }

    cout << maxFlow() << endl;
}
