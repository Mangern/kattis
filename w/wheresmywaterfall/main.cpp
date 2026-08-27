#include <bits/stdc++.h>
using namespace std;
using ii = array<int, 2>;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> cols(k);
    for (auto &c : cols) cin >> c;

    vector<string> grid(n + 2, string(m + 2, 'X'));

    for (int i = 0; i < n + 2; ++i) {
        string s;
        if (1 <= i && i <= n) {
            cin >> s;
        }

        for (int j = 0; j < m + 2; ++j) {
            if (1 <= i && i <= n && 1 <= j && j <= m) {
                grid[i][j] = s[j-1];
            }
        }
    }


    queue<ii> q;
    for (int c : cols) {
        q.push({1, c+1});
        grid[1][c+1] = '~';
    }

    while (q.size()) {
        auto [i, j] = q.front();
        q.pop();

        vector<ii> neis;

        if (grid[i+1][j] == 'O') {
            neis.push_back({i + 1, j});
        } else if (grid[i+1][j] != '~' && grid[i+1][j] != 'X') {
            if (grid[i][j-1] == 'O') neis.push_back({i, j - 1});
            if (grid[i][j+1] == 'O') neis.push_back({i, j + 1});
        }

        for (auto [ni, nj] : neis) {
            grid[ni][nj] = '~';
            q.push({ni, nj});
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << grid[i][j];
        }
        cout << endl;
    }
}
