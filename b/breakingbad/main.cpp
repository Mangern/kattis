#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5+5;


string item[mxN];
map<string, int> id;
int n, m;
vector<int> adj[mxN];
int col[mxN];

bool dfs(int u) {
    for (int v : adj[u]) {
        if (!col[v]) {
            col[v] = 3 ^ col[u];
            if (!dfs(v)) return false;
        } else if (col[v] == col[u]) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> item[i];
        id[item[i]] = i;
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
        string s, t;
        cin >> s >> t;
        int u = id[s];
        int v = id[t];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; ++i) {
        if (!col[i]) {
            col[i] = 1;
            if (!dfs(i)) {
                cout << "impossible" << endl;
                return 0;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (col[i] == 1) {
            cout << item[i] << " ";
        }
    }
    cout << endl;

    for (int i = 0; i < n; ++i) {
        if (col[i] == 2) {
            cout << item[i] << " ";
        }
    }
    cout << endl;

}
