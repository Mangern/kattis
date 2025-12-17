#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> row(n), col(m);
    for (auto & x : row) cin >> x;
    for (auto & y : col) cin >> y;

    vector<vector<int>> grid(n, vector<int>(m, 0));

    for (int i = 0; i < n; ++i) {
        bool has=0;
        for (int j = 0; j < m; ++j) {
            if (col[j] >= row[i]) {
                grid[i][j] = row[i];
                has=1;
            } else {
                grid[i][j] = col[j];
            }
        }
        if (!has) {
            cout << "impossible" << endl;
            return 0;
        }
    }


    vector<int> got(m);
    for (int j = 0; j < m; ++j) {
        got[j] = grid[0][j];
        for (int i = 0; i < n; ++i) {
            got[j] = max(got[j], grid[i][j]);
        }
    }

    cout << (got == col ? "possible" : "impossible") << endl;
}
