#include <bits/stdc++.h>
using namespace std;

const int mxN = 125;

int n;
int f[mxN][mxN];

int main() {
    cin >> n;
    for (int i = 0; i < n * n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        f[a][b] = c;
    }

    // assoc: (a * b) * c == a * (b * c)
    bool assoc = true;

    for (int a = 0; a < n; ++a) {
        for (int b = 0; b < n; ++b) {
            for (int c = 0; c < n; ++c) {
                if (f[f[a][b]][c] != f[a][f[b][c]]) {
                    assoc = false;
                }
            }
        }
    }

    if (!assoc) {
        cout << "magma" << endl;
        return 0;
    }
    int id = -1;
    // id: id * x == x * id == x for all x

    for (int i = 0; i < n; ++i) {
        bool fail = 0;
        for (int x = 0; x < n; ++x) {
            if (f[x][i] != f[i][x] || f[i][x] != x) {
                fail = 1;
            }
        }

        if (!fail) id = i;
    }

    if (id == -1) {
        cout << "semigroup" << endl;
        return 0;
    }

    // inverse: for each x there exists a y such that x * y == y * x == id
    bool inv = true;
    for (int x = 0; x < n; ++x) {
        bool found = 0;
        for (int y = 0; y < n; ++y) {
            if (f[x][y] == f[y][x] && f[x][y] == id) {
                found=1;
                break;
            }
        }

        if (!found)inv = false;
    }

    if (!inv) {
        cout << "monoid" << endl;
    } else {
        cout << "group" << endl;
    }
}
