#include <bits/stdc++.h>
using namespace std;

int di[8] = { -1, -1, 0, 1, 1,  1,  0, -1 };
int dj[8] = {  0,  1, 1, 1, 0, -1, -1, -1 };

int main() {
    vector<string> board(8);
    for (auto& s : board) cin >> s;

    int wini = 0, winj = 0;
    int ans = 0;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] != '.') continue;

            int cur = 0;
            for (int dir = 0; dir < 8; ++dir) {
                int ci = i;
                int cj = j;
                int cnt = 0;
                int good = 0;

                for (;;) {
                    ci += di[dir];
                    cj += dj[dir];

                    if (ci < 0 || 7 < ci || cj < 0 || 7 < cj) break;
                    if (board[ci][cj] == '.') break;
                    if (board[ci][cj] == 'B') {
                        good = 1;
                        break;
                    }
                    ++cnt;
                }
                if (good) cur += cnt;
            }

            if (cur > ans) {
                wini = i;
                winj = j;
                ans = cur;
            }
        }
    }
    cout << wini << " " << winj << endl;
}
