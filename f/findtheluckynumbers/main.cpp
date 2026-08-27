#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    int s;
    cin >> s;

    for (auto & v: grid) 
        for (auto & w: v) cin >> w;

    int ans=0;
    for (int i = 1; i < n - 1; ++i) {
        for (int j = 1; j < m - 1; ++j) if (grid[i][j] == s) {
            int t = grid[i-1][j-1]+grid[i-1][j+1]+grid[i+1][j-1]+grid[i+1][j+1];
            ans += (t % s == 0);
        }
    }
    cout << ans << endl;
}
