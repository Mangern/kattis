#include <bits/stdc++.h>
using namespace std;
using ii = array<int, 2>;

const int mxN = 505;

bool vis[2][mxN][mxN];

vector<ii> move1, move2;

int main() {
    int n;
    cin >> n;
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    move1 = {
        {-a, -b},
        {-a, b},
        {-b, -a},
        {-b, a},
        {a, -b},
        {a, b},
        {b, -a},
        {b, a},
    };
    move2 = {
        {-c, -d},
        {-c, d},
        {-d, -c},
        {-d, c},
        {c, -d},
        {c, d},
        {d, -c},
        {d, c},
    };

    vector<vector<ii>> moves = {move1, move2};

    queue<pair<ii, int>> q;
    vis[0][0][0] = 1;
    vis[1][0][0] = 1;
    q.push({{0,0}, 0});
    q.push({{0,0}, 1});

    while (q.size()) {
        auto [pos, f] = q.front();
        q.pop();

        auto [i, j] = pos;

        for (auto [di, dj] : moves[f]) {
            int ni = i + di;
            int nj = j + dj;
            int nf = 1 - f;

            if (ni < 0 || ni >= n || nj < 0 || nj >= n) {
                continue;
            }

            if (!vis[nf][ni][nj]) {
                vis[nf][ni][nj] = 1;

                q.push({{ni,nj}, nf});
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
        if (vis[0][i][j] || vis[1][i][j])++ans;
    }
    cout << ans << endl;
}
