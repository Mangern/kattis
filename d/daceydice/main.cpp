#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

struct state {
    int row;
    int col;
    int top;
    int rgt;
    int upw;

    bool operator<(const state& o) const {
        return make_tuple(row,col,top,rgt,upw) < make_tuple(o.row,o.col,o.top,o.rgt,o.upw);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for (auto &s : grid) cin >> s;

    state start;

    int goal_i, goal_j;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 'S') {
                start.row = i;
                start.col = j;
            }
            if (grid[i][j] == 'H') {
                goal_i = i;
                goal_j = j;
            }
        }
    }

    start.top = 4;
    start.rgt = 2;
    start.upw = 1;

    auto neighbors = [&](const state& s) {
        vector<state> ret;
        if (s.row + 1 < n && grid[s.row+1][s.col] != '*') {
            ret.push_back(state{
                .row = s.row + 1,
                .col = s.col,
                .top = 7 - s.upw,
                .rgt = s.rgt,
                .upw = s.top
            });
        }
        if (s.row - 1 >= 0 && grid[s.row-1][s.col] != '*') {
            ret.push_back(state{
                .row = s.row - 1,
                .col = s.col,
                .top = s.upw,
                .rgt = s.rgt,
                .upw = 7 - s.top,
            });
        }
        if (s.col + 1 < n && grid[s.row][s.col+1] != '*') {
            ret.push_back(state{
                .row = s.row,
                .col = s.col+1,
                .top = s.top,
                .rgt = s.upw,
                .upw = 7 - s.rgt,
            });
        }
        if (s.col - 1 >= 0 && grid[s.row][s.col-1] != '*') {
            ret.push_back(state{
                .row = s.row,
                .col = s.col-1,
                .top = s.top,
                .rgt = 7 - s.upw,
                .upw = s.rgt,
            });
        }
        return ret;
    };

    set<state> vis;
    vis.insert(start);
    queue<state> q;
    q.push(start);

    while (q.size()) {
        auto u = q.front();
        q.pop();
        if (u.row == goal_i && u.col == goal_j && 7 - u.upw == 5) {
            cout << "Yes" << endl;
            return;
        }
        for (auto v : neighbors(u)) {
            if (!vis.count(v)) {
                vis.insert(v);
                q.push(v);
            }
        }
    }
    cout << "No" << endl;
}

int main() {
    int T;
    cin >> T;
    while (T-->0)solve();
}
