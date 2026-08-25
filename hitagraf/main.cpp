#include <bits/stdc++.h>
using namespace std;

int main() {
    int h;
    cin >> h;
    int b;
    cin >> b;
    vector<string> grid(h, string(b, 'H'));

    for (int i = 0; i < h * b; ++i) {
        int r, c;
        cin >> r >> c, --r, --c;
        int t;
        cin >> t;
        grid[r][c] = "Kk.hH"[(t-1)/80];
    }

    for (auto row : grid) cout << row << endl;
}
