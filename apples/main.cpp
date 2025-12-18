#include <bits/stdc++.h>
using namespace std;

const int mxN = 5e4+5;

int afront, aback;
int avail_buf[mxN];

int navail() {
    return aback - afront;
}

int pop() {
    return avail_buf[afront++];
}

void push(int a) {
    avail_buf[aback++] = a;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);

    for (auto &s : grid) cin >> s;

    for (int j = 0; j < m; ++j) {
        afront = aback = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (grid[i][j] == '.') {
                push(i);
                continue;
            }
            if (grid[i][j] == '#') {
                afront = aback = 0;
            }
            if (grid[i][j] == 'a' && navail() > 0) {
                int sw = pop();
                swap(grid[sw][j], grid[i][j]);
                push(i);
            }
        }
    }

    for (auto s : grid)cout << s << endl;
}
