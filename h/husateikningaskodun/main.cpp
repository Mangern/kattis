#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int h = -1, w = -1;
    vector<string> grid(n); 
    int cnt = 0;
    for (auto &s : grid) {
        cin >> s;
        for (char c : s) if (c == '-')++cnt;
    }

    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
        if (grid[i][j] != '-') continue;

        int ii, jj;
        for (jj = j; jj < m; ++jj) {
            if (grid[i][jj] != '-') break;
        }
        w = jj - j;

        for (ii = i + 1; ii < n; ++ii) {
            bool ok=1;
            for (jj = j; jj < j + w; ++jj) {
                if (grid[ii][jj] != '-') {
                    ok=0;
                    break;
                }
            }
            if (!ok) break;
        }
        h = ii - i;

        if (h * w != cnt) {
            cout << "Neibb" << endl;
            return 0;
        }
        cout << n << " " << m << " " << h << " " << w << endl;
        return 0;
    }
    cout << "Neibb" << endl;
    return 0;
}
