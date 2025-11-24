#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (auto &s: grid) cin >> s;

    for (int j = 0; j < m; ++j) {
        for (int i = n - 1; i >= 0; --i) {
            int k = i;
            while (k < n - 1 && grid[k][j] == 'S' && grid[k+1][j] == '.') {
                swap(grid[k][j], grid[k+1][j]);
                ++k;
            }
        }
    }

    for (auto s : grid) {
        cout << s << endl;
    }
}
