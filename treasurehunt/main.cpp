#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    for (auto & s : grid) cin >> s;

    int i = 0;
    int j = 0;

    int ans = 0;

    for (;grid[i][j] != 'T';) {
        vis[i][j] = 1;
        int ni,nj;
        switch(grid[i][j]) {
            case 'S':
                ni = i + 1;
                nj = j;
                break;
            case 'N':
                ni = i - 1;
                nj = j;
                break;
            case 'E':
                ni = i;
                nj = j + 1;
                break;
            case 'W':
                ni = i;
                nj = j - 1;
                break;
        }

        if (ni < 0 || ni >= n || nj < 0 || nj >= m) {
            cout << "Out" << endl;
            return 0;
        }

        if (vis[ni][nj]) {
            cout << "Lost" << endl;
            return 0;
        }

        ++ans;
        i = ni;
        j = nj;
    }
    cout << ans << endl;
}
