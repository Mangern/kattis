#include <bits/stdc++.h>
using namespace std;

void rot90(const vector<string>& in, vector<string>& out) {
    int n = in.size();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            out[i][j] = in[n-1-j][i];
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<string>> grids(4, vector<string>(n, string(n, '.')));

    for (auto &s : grids[0]) cin >> s;

    for (int i = 1; i < 4; ++i) {
        rot90(grids[i-1], grids[i]);
    }
    string msg;
    cin >> msg;

    vector<string> ans(n, string(n, '?'));

    int ptr = 0;
    for (int r = 0; r < 4; ++r) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grids[r][i][j] == '.') {
                    if (ans[i][j] != '?') {
                        cout << "invalid grille" << endl;
                        return 0;
                    }
                    ans[i][j] = msg[ptr++];
                }
            }
        }
    }

    if (ptr != msg.length()) {
        cout << "invalid grille" << endl;
    } else {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << ans[i][j];
            }
        }
        cout << endl;
    }
}
