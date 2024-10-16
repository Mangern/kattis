#include <bits/stdc++.h>
#include <vector>
using namespace std;

const int mxN = 51;

int r, k;
int grid[2*mxN][2*mxN];
int vis[2 * mxN][2*mxN];

void indexof(int val, int& i, int& j) {
    for (i = 0; i < 2 * mxN; ++i) {
        for (j = 0; j < 2 * mxN; ++j) {
            if (grid[i][j] == val)return;
        }
    }
}

vector<pair<int,int>> neis(int i, int j) {
    return vector<pair<int,int>>{{i-1,j},{i,j+1},{i+1,j+1},{i+1,j},{i,j-1},{i-1,j-1}};
}

int main() {

    for (int i = 0; i < 2 * mxN; ++i) {
        memset(grid[i], -1, sizeof grid[0]);
    }

    scanf("%d%d",&r,&k);

    int tim = 1;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < r + i; ++j) {
            grid[1+i][1+j] = tim;
            ++tim;
        }
    }
    for (int i = 0; i < r - 1; ++i) {
        for (int j = i+1; j < 2 * r - 1; ++j) {
            grid[1+r+i][1+j] = tim;
            ++tim;
        }
    }

    vector<int> inp(k);
    for (auto& x : inp)cin >> x;

    int ans = 0;

    for (int x : inp) {
        int i,j;
        indexof(x, i, j);
        vis[i][j] = 1;
    }

    vis[0][0] = 2;

    queue<pair<int,int>> q;
    q.push({0, 0});

    while (q.size()) {
        auto [i, j] = q.front();
        q.pop();

        for (auto [ni, nj] : neis(i, j)) {
            if (ni < 0 || ni >= 2 * mxN || nj < 0 || nj >= 2 * mxN)continue;
            if (vis[ni][nj])continue;
            vis[ni][nj] = 2;
            q.push({ni,nj});
        }
    }

    for (int i = 0; i < 2 * mxN; ++i) for (int j = 0; j < 2 * mxN; ++j) {
        if (vis[i][j] == 0)inp.push_back(grid[i][j]);
    }

    for (int x : inp) {
        int i,j;
        indexof(x, i, j);
        vis[i][j] = 1;

        ans += 6;

        for (auto [ni, nj] : neis(i, j)) {
            if (ni < 0 || ni >= 2 * mxN || nj < 0 || nj >= 2 * mxN)continue;
            if (vis[ni][nj] != 2) {
                ans -= 1;
            }
        }
    }
    cout << ans << endl;
}
