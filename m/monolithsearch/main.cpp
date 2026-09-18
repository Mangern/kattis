#include <bits/stdc++.h>
using namespace std;

const int mxN = 505;

int n, m;
string grid[mxN];

bool ratio_ok(int a, int b) {
    if (a > b) swap(a, b);

    if (9 * a == b) return true;
    if (9 * a == 4 * b) return true;
    if (4 * a == b) return true;
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    int num_found = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '.') continue;
            int w;
            for (w = 0; j + w < m; ++w) {
                if (grid[i][j+w] == '.') break;
            }
            int h;
            for (h = 0; i + h < n; ++h) {
                if (grid[i+h][j] == '.') break;
            }

            if (w == 0 || h == 0) continue;

            bool ok=1;
            for (int ii = i - 1; ok && ii <= i + h; ++ii) {
                for (int jj = j - 1; ok && jj <= j + w; ++jj) {
                    if (ii < 0 || ii >= n) continue;
                    if (jj < 0 || jj >= m) continue;
                    if ((ii < i || ii == i + h) && grid[ii][jj] != '.') {
                        ok=0;
                        break;
                    }
                    if ((jj < j || jj == j + w) && grid[ii][jj] != '.') {
                        ok=0;
                        break;
                    }
                    if (i <= ii && ii < i + h && j <= jj && jj < j + w && grid[ii][jj] == '.') {
                        ok=0;
                        break;
                    }
                }
            }

            if (ok) {
                if (ratio_ok(w, h)) {
                    ++num_found;
                }
            }
        }
    }

    if (num_found == 1) cout << "Steinn fannst" << endl;
    else if (num_found > 1) cout << "Bilun" << endl;
    else cout << "Ekkert fannst" << endl;
}
