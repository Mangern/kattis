#include <bits/stdc++.h>
using namespace std;
using ii = array<int, 2>;

const int mxN = 405;

vector<string> grid;
ii p[mxN][mxN];

int main() {
    int n, m;
    cin >> n >> m;
    grid.resize(n);
    for (auto & s : grid) cin >> s;
    ii spos, tpos;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            p[i][j] = {-1,-1};
            if (grid[i][j] == 'A')spos={i,j};
            if (grid[i][j] == 'P')tpos={i,j};
        }
    }

    queue<ii> q;
    q.push(spos);
    p[spos[0]][spos[1]] = {-2,-2};

    while (q.size()) {
        auto [i, j] = q.front();
        q.pop();

        for (auto [ni, nj] : vector<ii>{{i-1,j},{i+1,j},{i,j-1},{i,j+1}}) {
            if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
            if (grid[ni][nj] == '#') continue;
            if (p[ni][nj][0] != -1) continue;

            p[ni][nj] = {i, j};
            q.push({ni,nj});
        }
    }

    if (p[tpos[0]][tpos[1]][0] == -1) {
        cout << "call for help" << endl;
        return 0;
    }

    auto ptr = p[tpos[0]][tpos[1]];

    while (ptr != spos) {
        grid[ptr[0]][ptr[1]] = 'X';
        ptr = p[ptr[0]][ptr[1]];
    }

    for (auto &s : grid)cout << s << endl;
}
