#include <bits/stdc++.h>
using namespace std;

int n, m;

int ans_i = -1, ans_j;

pair<int, int> simulate(const string &instr, int bi, int bj) {
    int i = 0, j = 0;

    for (char c : instr) {
        int ni, nj;
        switch (c) {
            case '>':
                ni = i;
                nj = j + 1;
                break;
            case '<':
                ni = i;
                nj = j - 1;
                break;
            case '^':
                ni = i - 1;
                nj = j;
                break;
            case 'v':
                ni = i + 1;
                nj = j;
                break;
            default:
                assert(false);
        }

        if (0 <= ni && ni < n && 0 <= nj && nj < m && !(ni == bi && nj == bj)) {
            i = ni;
            j = nj;
        }
    }

    return {i, j};
}

pair<int, int> ask(const string& path) {
    if (ans_i != -1) {
        return simulate(path, ans_i, ans_j);
    }
    cout << "? " << path << endl;
    cout.flush();

    int i, j;
    cin >> i >> j;
    return {i, j};
}

pair<int, int> solve() {
    if (n == 1) {
        string path(m - 1, '>');
        auto [i1, j1] = ask(path);
        return {0, j1 + 1};
    }
    if (m == 1) {
        string path(n - 1, 'v');
        auto [i1, j1] = ask(path);
        return {i1 + 1, 0};
    }
    if (m == 2) {
        string path; 
        path.push_back('>');
        path += string(n - 1, 'v');
        auto [i1, j1] = ask(path);

        if (i1 == n - 1 && j1 == 0) {
            return {0, 1};
        }

        if (i1 < n - 1) {
            return {i1+1, 1};
        }

        path = string(n - 1, 'v');

        auto [i2, j2] = ask(path);
        return {i2+1, 0};
    }
    string path;
    for (int j = 0; j < m - 1; ++j) {
        for (int i = 0; i < n - 1; ++i) {
            path.push_back('>');
            path.push_back('<');
            path.push_back('v');
        }
        for (int i = 0; i < n - 1; ++i) {
            path.push_back('>');
            path.push_back('<');
            path.push_back('^');
        }
        path.push_back('>');
    }

    auto [i1, j1] = ask(path);

    //cout << "Ended up at " << i1 << " " << j1 << endl;

    if (i1 == 0 && j1 == 0) {
        return {0, 1};
    }

    if (j1 == m - 1) {
        // got past it somehow
        // could be col 0 or 1
        path.clear();

        path.push_back('>');

        for (int i = 0; i < n - 1; ++i) {
            path.push_back('<');
            path.push_back('>');
            path.push_back('v');
        }

        // robot is either at {n-1,0} or {ans_i - 1, 1};

        path += "<<>>v<<^<v";

        path += ">vv<^";
        path += string(n - 1, '^');

        auto [i2, j2] = ask(path);

        if (j2 == 2) {
            return {n - 1, 1};
        }

        if (j2 == 1) {
            if (i2 == 0) {
                return {n - 1, 0};
            }
            return {i2 - 1, 1};
        }

        return {i2 - 1, 0};
    } else {
        // ans_j == j1 + 1
        path.clear();
        path += string(j1+1, '>');
        path += string(n - 1, 'v');

        auto [i2, j2] = ask(path);

        if (j2 == j1 + 1) {
            return {i2 + 1, j2};
        }
        return {0, j1 + 1};
    }
}

int main() {
    cin >> n >> m;
    auto [ri, rj] = solve();
    cout << "! " << ri << " " << rj << endl;
    return 0;
}
