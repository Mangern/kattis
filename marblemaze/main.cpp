#include <iostream>
#include <string>
#include <cassert>
using namespace std;

const int mxN = 12;

int w, h, n;
string grid[mxN];
bool state[mxN][mxN];
int x1, y1;

pair<int, int> sim(int x, int y) {
    char c = grid[y][x];

    switch(c) {
        case '.':
            return {x, y};
        case '<':
            return sim(x - 1, y);
        case '>':
            return sim(x + 1, y);
        case '^':
            return sim(x, y - 1);
        case 'v':
            return sim(x, y + 1);
        case '-':
            if (state[y][x]) {
                state[y][x] = 0;
                return sim(x + 1, y);
            } else {
                state[y][x] = 1;
                return sim(x - 1, y);
            }
        case '|':
            if (state[y][x]) {
                state[y][x] = 0;
                return sim(x, y + 1);
            } else {
                state[y][x] = 1;
                return sim(x, y - 1);
            }
    }
    assert(false);
}

int main() {
    cin >> w >> h >> n;

    for (int i = 0; i <= h + 1; ++i) {
        grid[i] = string(w + 2, '.');
    }

    cin >> x1 >> y1, ++x1, ++y1;

    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < w; ++j) {
            grid[i+1][j+1] = s[j];
        }
    }

    for (int i = 0; i < n; ++i) {
        auto [x, y] = sim(x1, y1);

        cout << x - 1 << " " << y - 1 << endl;
    }
}
