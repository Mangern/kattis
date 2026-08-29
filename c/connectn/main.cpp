#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    vector<string> board(h, string(w, '?'));

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (board[i][j] == 'O') continue;
            char c = board[i][j];
            bool hor=1,ver=1,diup=1,didw=1;
            for (int k = 0; k < n; ++k) {
                if (i - k < 0 || board[i-k][j] != c) {
                    hor=0;
                }
                if (j - k < 0 || board[i][j-k] != c) {
                    ver=0;
                }
                if (i - k < 0 || j - k < 0 || board[i-k][j-k] != c) {
                    diup=0;
                }
                if (i + k >= h || j - k < 0 || board[i+k][j-k] != c) {
                    didw=0;
                }
            }

            if (hor || ver || diup || didw) {
                cout << (c == 'R' ? "RED":"BLUE") << " WINS" << endl;
                return 0;
            }
        }
    }
    cout << "NONE" << endl;
}
