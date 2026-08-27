#include <bits/stdc++.h>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    string s;
    char c;
    ll t, d;
    cin >> s >> c >> t >> d;

    vector<string> grid(t + d + 1 + d + t, string(t + d + s.length() + d + t, ' '));

    for (int i = 0; i < t; ++i) for (int j = 0; j < grid[0].length(); ++j) {
        grid[i][j] = c;
        grid[grid.size() - 1 - i][j] = c;
    }

    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < t; ++j) {
            grid[i][j] = c;
            grid[i][grid[0].size() - 1 - j] = c;
        }
    }

    for (int j = t + d; j < t + d + s.length(); ++j) {
        grid[t+d][j] = s[j-t-d];
    }

    for (auto &s : grid) cout << s << endl;
}
