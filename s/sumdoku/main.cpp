#include <bits/stdc++.h>
using namespace std;

// row_cons[i][j]: symbol between (i, j-1) and (i, j)
// similar for col
string row_cons[9];
string col_cons[9];

int board[9][9];

void search(int idx = 0) {
    if (idx == 9 * 9) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (j > 0)cout << ' ';
                cout << board[i][j];
            }
            cout << endl;
        }
        exit(0);
    }
    int i = idx / 9;
    int j = idx % 9;

    for (int val = 1; val <= 9; ++val) {
        bool ok=1;
        for (int p = 0; p < j; ++p) {
            if (board[i][p] == val) {
                ok=0;
                break;
            }
        }
        if (!ok)continue;
        for (int p = 0; p < i; ++p) {
            if (board[p][j] == val) {
                ok=0;
                break;
            }
        }
        if (!ok)continue;

        int base_i = 3 * (i / 3);
        int base_j = 3 * (j / 3);
        for (int ii = base_i; ii < base_i + 3; ++ii) {
            for (int jj = base_j; jj < base_j + 3; ++jj) {
                if (board[ii][jj] == val) {
                    ok=0;
                }
            }
        }
        if (!ok)continue;

        if (row_cons[i][j] == '<') {
            if (board[i][j-1] + val >= 10) continue;
        } else if (row_cons[i][j] == '=') {
            if (board[i][j-1] + val != 10) continue;
        } else if (row_cons[i][j] == '>') {
            if (board[i][j-1] + val <= 10) continue;
        }

        if (col_cons[j][i] == '<') {
            if (board[i-1][j] + val >= 10) continue;
        } else if (col_cons[j][i] == '=') {
            if (board[i-1][j] + val != 10) continue;
        } else if (col_cons[j][i] == '>') {
            if (board[i-1][j] + val <= 10) continue;
        }

        board[i][j] = val;
        search(idx + 1);
        board[i][j] = 0;
    }
}

int main() {
    for (int i = 0; i < 9; ++i) {
        col_cons[i].push_back('x');
    }
    for (int i = 0; i < 9; ++i) {
        string s;
        cin >> s;
        int ptr = 0;
        for (int j = 0; j < 3; ++j) {
            row_cons[i].push_back('x');
            row_cons[i].push_back(s[ptr++]);
            row_cons[i].push_back(s[ptr++]);
        }
        if (i % 3 != 2) {
            string s;
            cin >> s;

            for (int j = 0; j < 9; ++j) {
                col_cons[j].push_back(s[j]);
                if (col_cons[j].size() % 3 == 0) {
                    col_cons[j].push_back('x');
                }
            }
        }
    }
    search();
}
