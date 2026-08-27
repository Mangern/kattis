#include <bits/stdc++.h>
using namespace std;

const int mxN = 1005;

int n, m;

vector<int> adj[mxN];
int in[mxN];

map<string,int> id;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        id[s] = i;
    }

    int idptr = n;
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        
        string src;
        cin >> src;

        if (!id.count(src))id[src] = idptr++;

        int u = id[src];

        for (int j = 0; j < k - 1; ++j) {
            string dst;
            cin >> dst;
            if (!id.count(dst))id[dst] = idptr++;
            adj[id[dst]].push_back(u);
            ++in[u];
        }
    }

    int cr=0;

    queue<int> q;
    for (int i = 0; i < n + m; ++i) {
        if (!in[i])q.push(i);
    }

    while (q.size()) {
        int u = q.front();
        q.pop();

        if (u >= n)++cr;

        for (int v : adj[u]) {
            if (!--in[v])q.push(v);
        }
    }

    if (cr == m) cout << "GUARANTEED VICTORY" << endl;
    else cout << m - cr << endl;
}
