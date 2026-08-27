#include <array>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void solve(vector<string>& grid) {
    map<int, array<int, 2>> pos;

    static const string alph = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            if (grid[i][j] == '.')continue;

            int id = alph.find(grid[i][j]);
            pos[id] = {i, j};
        }
    }

    for (int i = 0; i < pos.size() - 1; ++i) {
        auto [si, sj] = pos[i];
        auto [ti, tj] = pos[i+1];

        char c;

        if (si == ti)c = '-';
        else c = '|';

        while (si != ti || sj != tj) {
            if (grid[si][sj] == '.')grid[si][sj] = c;
            else if (grid[si][sj] == ('|'^'-'^c))grid[si][sj] = '+';

            if (c == '-') {
                if (sj < tj)++sj;
                else --sj;
            } else {
                if (si < ti)++si;
                else --si;
            }
        }
    }

    for (const auto& s : grid) {
        cout << s << endl;
    }
}

int main() {
    vector<string> rows;
    string line;
    bool f = 0;
    while (getline(cin, line)) {
        if (line.empty()) {
            if (f)cout << endl;
            else f = 1;
            solve(rows);
            rows.clear();
        } else {
            rows.push_back(line);
        }
    }
    if (f)cout << endl;
    solve(rows);
}
