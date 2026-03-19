#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (auto &s : grid) cin >> s;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'W') {
                if(i>0 && grid[i-1][j] == 'O'
                 || j>0 && grid[i][j-1] == 'O'
                 || i+1<n && grid[i+1][j] == 'O'
                 || j+1<m && grid[i][j+1] == 'O')++ans;
            }
        }
    }
    cout << ans << endl;
}
