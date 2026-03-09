#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = numeric_limits<ll>::max() / 4;

const int mxN = 501;

int n, m;
string grid[mxN];

struct state {
    array<ll, 3> pos;
    array<ll, 2> d;

    bool operator<(const state& other) const {
        if (d == other.d) {
            return pos < other.pos;
        }
        return d > other.d;
    }
};

array<ll, 2> dist[mxN][mxN][2];

bool isgood(char c) {
    return c == ' ' or c == 'X';
}

int main() {
    string line;
    getline(cin, line);
    stringstream ss{line};
    ss >> m >> n;
    int si, sj;
    for (int i = 0; i < n; ++i) {
        getline(cin, line);
        grid[i] = line;
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '@') {
                grid[i][j] = ' ';
                si = i;
                sj = j;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        // cout << grid[i] << endl;
        for (int j = 0; j < m; ++j) {
            dist[i][j][0] = {INF, INF};
            dist[i][j][1] = {INF, INF};
        }
    }

    dist[si][sj][0] = {0, 0};

    priority_queue<state> pq;
    using tup = array<ll, 3>;
    using ii = array<ll, 2>;
    pq.push({tup{si, sj, 0}, ii{0, 0}});

    while (pq.size()) {
        auto [pos, d] = pq.top();
        pq.pop();
        auto [i, j, g] = pos;
        // cout << i << " " << j << " " << g << endl;
        if (dist[i][j][g] < d) continue;

        vector<state> neis;

        if (g) {
            if (i - 1 >= 0 && isgood(grid[i-1][j])) {
                neis.push_back({tup{i-1, j, g}, d});
            } else if (i - 1 >= 0 && grid[i-1][j] == '#') {
                if (j + 1 < m && isgood(grid[i][j+1])) {
                    neis.push_back({tup{i, j+1, g}, ii{d[0], d[1] + 1}});
                }
                if (j > 0 && isgood(grid[i][j-1])) {
                    neis.push_back({tup{i, j - 1, g}, ii{d[0], d[1] + 1}});
                }
                neis.push_back({tup{i, j, 1 - g}, ii{d[0] + 1, d[1] + 1}});
            } else {
                // dead
            }
        } else {
            if (i + 1 < n && isgood(grid[i+1][j])) {
                neis.push_back({tup{i+1, j, g}, d});
            } else if (i + 1 < n && grid[i+1][j] == '#') {
                if (j + 1 < m && isgood(grid[i][j+1])) {
                    neis.push_back({tup{i, j+1, g}, ii{d[0], d[1] + 1}});
                }
                if (j > 0 && isgood(grid[i][j-1])) {
                    neis.push_back({tup{i, j - 1, g}, ii{d[0], d[1] + 1}});
                }
                neis.push_back({tup{i, j, 1 - g}, ii{d[0] + 1, d[1] + 1}});
            } else {
                // dead.
            }
        }

        for (auto s : neis) {
            auto [ni, nj, ng] = s.pos;
            if (s.d < dist[ni][nj][ng]) {
                dist[ni][nj][ng] = s.d;
                pq.push(s);
            }
        }
    }

    array<ll, 2> ans = {INF, INF};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'X') {
                ans = min(ans, dist[i][j][0]);
                ans = min(ans, dist[i][j][1]);
            }
        }
    }

    if (ans[0] == INF) {
        cout << "impossible!" << endl;
    } else {
        cout << ans[0] << " " << ans[1] << endl;
    }
}
