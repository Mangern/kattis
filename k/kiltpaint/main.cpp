#include <bits/stdc++.h>
using namespace std;

const int mxN = 205;

int n, m;

string grid[mxN];

// rows: [0..n)
// cols: [n..n+m)
vector<pair<int, char>> solve() {
    // assume each row is painted
    vector<pair<int, char>> ret;
    for (int free_col = 0; free_col < m; ++free_col) {
        string row_chars(n,'?');
        for (int i = 0; i < n; ++i) {
            row_chars[i] = grid[i][free_col];
        }

        vector<vector<int>> adj(n+m);
        vector<int> in(n+m,0);
        vector<bool> ignore(n+m,0);
        string col_chars(m, '?');
        bool fail = 0;
        for (int i = 0; i < n && !fail; ++i) {
            for (int j = 0; j < m && !fail; ++j) {
                if (grid[i][j] != row_chars[i]) {
                    if (col_chars[j] != '?' && col_chars[j] != grid[i][j]) {
                        fail=1;
                        break;
                    }
                    col_chars[j] = grid[i][j];
                    // Need to paint the row before this column
                    adj[i].push_back(n + j);
                    ++in[n+j];
                }
            }
        }
        if (fail) {
            continue;
        }
        // some columns will be painted: 
        // for each character matching the row char here, the column must be painted first
        int tot = n;
        for (int j = 0; j < m; ++j) {
            if (col_chars[j] == '?') {
                ignore[n+j] = 1;
                continue;
            }
            ++tot;
            for (int i = 0; i < n; ++i) {
                if (grid[i][j] == row_chars[i] && grid[i][j] != col_chars[j]) {
                    adj[n + j].push_back(i);
                    ++in[i];
                }
            }
        }

        queue<int> q;
        for (int i = 0; i < n + m; ++i) {
            if (ignore[i])continue;
            if (!in[i]) q.push(i);
        }
        vector<int> topo;
        while (q.size()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);

            for (int v : adj[u]) {
                if (!--in[v]) {
                    q.push(v);
                }
            }
        }
        if (topo.size() != tot) {
            continue;
        }

        vector<pair<int, char>> here;
        for (int i : topo) {
            if (i < n) {
                here.emplace_back(i, row_chars[i]);
            } else {
                here.emplace_back(i, col_chars[i - n]);
            }
        }
        if (ret.empty() || ret.size() > here.size()) {
            swap(ret, here);
        }
    }
    return ret;
}

void transpose() {
    vector<string> ngrid(m, string(n, '?'));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ngrid[j][i] = grid[i][j];
        }
    }
    for (int i = 0; i < m; ++i) {
        grid[i] = ngrid[i];
    }
    swap(n, m);
}

void transpose_ans(vector<pair<int, char>>& ans) {
    for (auto &[i, c] : ans) {
        if (i < m) {
            i = i + n;
        } else {
            i = i - m;
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    auto ans = solve();
    transpose();
    auto anst = solve();
    transpose();

    if (anst.size()) {
        transpose_ans(anst);
    }

    vector<pair<int, char>> fin;
    if (ans.empty())fin = anst;
    else if (anst.empty())fin = ans;
    else if (ans.size() < anst.size())fin = ans;
    else fin = anst;

    if (fin.empty()) {
        cout << "impossible" << endl;
        return 0;
    }

    cout << fin.size() << endl;
    for (auto [i, c] : fin) {
        if (i < n) {
            cout << "y=" << i+1 << ' ' << c << '\n';
        } else {
            cout << "x=" << (i-n+1) << ' ' << c << '\n';
        }
    }
}
