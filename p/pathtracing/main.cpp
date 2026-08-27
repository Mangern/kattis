#include <bits/stdc++.h>
using namespace std;
using ii = array<int, 2>;

int main() {
    string instr;
    int x = 0;
    int y = 0;
    vector<ii> path = {{0,0}};
    while (getline(cin, instr)) {
        if (instr == "down") {
            y += 1;
        }
        if (instr == "up") {
            y -= 1;
        }
        if (instr == "left") {
            x -= 1;
        }
        if (instr == "right") {
            x += 1;
        }
        path.push_back({x,y});
    }

    int minx = INT_MAX, maxx = -INT_MAX, miny = INT_MAX, maxy = -INT_MAX;

    for (auto [x, y] : path) {
        minx = min(minx, x);
        miny = min(miny, y);
        maxx = max(maxx, x);
        maxy = max(maxy, y);
    }
    int n = maxy - miny + 1 + 2;
    int m = maxx - minx + 1 + 2;

    vector<string> grid(n, string(m, ' '));

    for (auto [x, y] : path) {
        grid[y-miny+1][x-minx+1] = '*';
    }
    {
        auto [x, y] = path[0];
        grid[y-miny+1][x-minx+1] = 'S';
    }
    {
        auto [x, y] = path.back();
        grid[y-miny+1][x-minx+1] = 'E';
    }

    for (int i = 0; i < n; ++i) {
        grid[i][0] = '#';
        grid[i][m-1] = '#';
    }
    for (int j = 0; j < m; ++j) {
        grid[0][j] = '#';
        grid[n-1][j] = '#';
    }
    for (const auto &s : grid) {
        cout << s << '\n';
    }
}
