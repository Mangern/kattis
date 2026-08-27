#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 10;
    vector<vector<int>> reg(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            reg[i][j] = s[j] - '0';
        }
    }

    vector<string> grid(n);
    for (auto &s : grid) cin >> s;

    vector<int> cnt(n, 0);
    vector<int> col(n, 0);
    vector<int> row(n, 0);
    bool valid=1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '*') {
                ++cnt[reg[i][j]];
                ++col[j];
                ++row[i];

                if (i >0 && grid[i-1][j] == '*') {
                    cout << "invalid" << endl;
                    return 0;
                }
                if (j > 0 && grid[i][j-1] == '*') {
                    cout << "invalid" << endl;
                    return 0;
                }
                if (i > 0 && j > 0 && grid[i-1][j-1] == '*') {
                    cout << "invalid" << endl;
                    return 0;
                }
                if (i < n - 1 && j > 0 && grid[i+1][j-1] == '*') {
                    cout << "invalid" << endl;
                    return 0;
                }
            }
        }
    }

    for (auto &v: vector<vector<int>>{cnt,col,row}) {
        if (*max_element(begin(v), end(v)) != 2 || *min_element(begin(v), end(v)) != 2) {
            cout << "invalid" << endl;
            return 0;
        }
    }

    cout << "valid" << endl;
}
