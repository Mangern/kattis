#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;
using ii = array<int,2>;

void solve() {
    int w, h, n;
    cin >> w >> h >> n;

    string grid1(w * h, '_');
    string grid2(w * h, '_');

    vector<bool> hit1(w * h, 0);
    vector<bool> hit2(w * h, 0);

    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;

        for (int j = i * w; j < i * w + w; ++j) {
            grid1[j] = s[j - i * w];
        }
    }
    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;

        for (int j = i * w; j < i * w + w; ++j) {
            grid2[j] = s[j - i * w];
        }
    }
    bool turn = 0;
    bool done = false;
    bool left1 = true;
    bool left2 = true;
    for (int _ = 0; _ < n; ++_) {
        int i, j;
        cin >> j >> i;
        if (done)continue;
        i = h - 1 - i;
        int idx = i * w + j;

        if (turn) {
            if (!left1) {
                if (!left2)done = 1;
                continue;
            }
            if (hit1[idx] || grid1[idx] == '_') {
                turn = !turn;
                if (!left2)done = 1;
            } else {
                hit1[idx] = 1;
            }
        } else {
            if (!left1)continue;
            if (hit2[idx] || grid2[idx] == '_') {
                turn = !turn;
            } else {
                hit2[idx] = 1;
            }
        }
        left1 = false;
        left2 = false;
        for (int i = 0; i < w * h; ++i) {
            if (!hit1[i] && grid1[i] == '#')left1 = true;
            if (!hit2[i] && grid2[i] == '#')left2 = true;
        }

        if (!turn && !left2) {
            turn = !turn;
        }
    }
    if ((!left1 && !left2) || (left1 && left2)) {
        cout << "draw" << endl;
    } else if (left1) {
        cout << "player one wins" << endl;
    } else {
        cout << "player two wins" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t-->0)solve();
}
