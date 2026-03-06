#include <bits/stdc++.h>
using namespace std;

const int mxN = 21;

int row_sz[mxN];
char table[mxN][mxN];

void rot90() {
    char ntable[mxN][mxN];

    for (int i = 0; i < mxN; ++i) {
        for (int j = 0; j < mxN; ++j) {
            ntable[j][mxN-i-1] = table[i][j];
        }
    }

    for (int i = 0; i < mxN; ++i) {
        for (int j = 0; j < mxN; ++j) {
            table[i][j] = ntable[i][j];
        }
    }
}

int main() {
    int r, c;
    cin >> r >> c;
    vector<string> inp(r);
    for (auto &s: inp) cin >> s;
    int d;
    cin >> d;
    bool mode45 = 0;
    if (d % 90 == 0) {
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                table[i][row_sz[i]++] = inp[i][j];
            }
        }
    } else if ((d / 90) % 2 == 0) {
        mode45 = 1;
        d -= 45;
        for (int j = 0; j < c; ++j) {
            for (int i = 0; i < r; ++i) {
                int rw = (i + j);
                table[rw][row_sz[rw]++] = inp[i][j];
            }
        }
    } else {
        mode45 = 1;
        d += 45;
        for (int j = 0; j < c; ++j) {
            for (int i = 0; i < r; ++i) {
                int rw = (i + c - j - 1);
                table[rw][row_sz[rw]++] = inp[i][j];
            }
        }
    }

    for (int i = 0; i < (d / 90); ++i) {
        rot90();
    }

    vector<string> out;
    for (int i = 0; i < mxN; ++i) {
        string cur;
        for (int j = 0; j < mxN; ++j) {
            if (table[i][j]) {
                if (mode45 && cur.size() > 0) {
                    cur.push_back(' ');
                }
                cur.push_back(table[i][j]);
            }
        }
        if (cur.size())out.push_back(cur);
    }

    if (mode45) {
        int mlen = 0;
        for (int i = 0; i < out.size(); ++i) {
            if (out[i].size() > out[mlen].size()) {
                mlen = i;
            }
        }

        for (int i = mlen - 1; i >= 0; --i) {
            int nspace = mlen - i;
            out[i] = string(nspace, ' ') + out[i];
        }
        for (int i = mlen + 1; i < out.size(); ++i) {
            int nspace = i - mlen;
            out[i] = string(nspace, ' ') + out[i];
        }
    }

    for (auto row : out) {
        cout << row << endl;
    }
}
