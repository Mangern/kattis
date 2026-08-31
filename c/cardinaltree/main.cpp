#include <bits/stdc++.h>
using namespace std;
int needle[5][3] = {
    {4,2,6},
    {2,1,1},
    {5,2,6},
    {1,1,2},
    {5,2,3},
};
int n,m;
int grid[1010][1010];
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> grid[i][j];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            bool ok=1;
            for (int ii = 0; ii < 5; ++ii) {
                for (int jj = 0; jj < 3; ++jj) {
                    if (grid[i+ii][j+jj] != needle[ii][jj]) {
                        ok=0;
                        break;
                    }
                }
            }

            if (ok) {
                cout << i+1 << " " << j+1 << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
}
