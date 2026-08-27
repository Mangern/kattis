#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    string kind;
    cin >> n >> m >> kind;

    char falcon = kind[1];

    vector<string> grid1(n), grid2(n);
    for (auto &s : grid1) cin >> s;
    for (auto &s : grid2) cin >> s;

    vector<pair<int,int>> pat;
    int pati = -1, patj = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid1[i][j] == falcon) {
                if (pati == -1) {
                    pati = i;
                    patj = j;
                }
                pat.push_back({i - pati, j - patj});
            }
        }
    }

    bool ok = 0;
    int di, dj;
    for (int i = 0; i < n && !ok; ++i) {
        for (int j = 0; j < m && !ok; ++j) {
            if (grid2[i][j] == falcon) {
                di = i - pati;
                dj = j - patj;
                ok = 1;
            }
        }
    }

    assert(ok);

    vector<string> ans(n, string(m, '?'));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid1[i][j] != falcon)ans[i][j] = grid1[i][j];
            if (grid2[i][j] != falcon)ans[i][j] = grid2[i][j];
        }
    }

    for (auto [pi, pj] : pat) {
        int ai = pati + 2 * di + pi;
        int aj = patj + 2 * dj + pj;
        if (0 <= ai && ai < n && 0 <= aj && aj < m) {
            ans[ai][aj] = falcon;
        }
    }

    for (auto s : ans)cout << s << endl;
}
