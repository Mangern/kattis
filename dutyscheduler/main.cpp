#include <bits/stdc++.h>
#include <cassert>
using namespace std;

const int mxM = 64;
const int mxN = 32;

int n, m;
int s,t;
string id[mxM];

vector<int> days[mxM];
int adj[mxN+mxM][mxN+mxM];
int cf[mxN+mxM];
bool vis[mxN + mxM];

bool bfs() {
    memset(cf, -1, sizeof cf);
    memset(vis, 0, sizeof vis);
    queue<int> q;
    q.push(s);
    vis[s] = 1;

    while (q.size()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < mxN+mxM; ++v) if (!vis[v]) {
            if (adj[u][v] > 0) {
                cf[v] = u;
                vis[v] = 1;
                q.push(v);
            }
        }
    }

    return cf[t] != -1;
}

int max_flow() {
    int mf = 0;
    while (bfs()) {
        int bottle = 100000;
        for (int ptr = t; cf[ptr] != -1; ptr = cf[ptr]) {
            bottle = min(bottle, adj[cf[ptr]][ptr]);
        }

        mf += bottle;

        for (int ptr = t; cf[ptr] != -1; ptr = cf[ptr]) {
            adj[cf[ptr]][ptr] -= bottle;
            adj[ptr][cf[ptr]] += bottle;
        }
    }
    return mf;
}

int main() {
    cin >> m >> n;

    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        id[i] = s;
        int d;
        cin >> d;

        for (int j = 0; j < d; ++j) {
            int u;
            cin >> u;
            days[i].push_back(u-1);
        }
    }

    s = n + m;
    t = n + m + 1;

    for (int max_cap = 1; ; ++max_cap) {
        for (int i = 0; i < mxN + mxM; ++i) {
            memset(adj[i], 0, sizeof adj[0]);
        }

        for (int i = 0; i < m; ++i) {
            adj[s][i+n] = max_cap;
            for (int u : days[i]) {
                adj[i+n][u] = 1;
                adj[u][t] = 2;
            }
        }
        int mf = max_flow();
        if (mf == 2 * n) {
            cout << max_cap << endl;

            for (int i = 0; i < n; ++i) {
                cout << "Day " << i+1 << ": ";
                for (int j = 0; j < m; ++j) {
                    if (find(begin(days[j]), end(days[j]), i) == end(days[j])) continue;
                    if (!adj[j+n][i]) {
                        cout << id[j] << " ";
                    }
                }
                cout << endl;
            }
            break;
        }
    }
}
