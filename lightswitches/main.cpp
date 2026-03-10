#include <bits/stdc++.h>
#include <sstream>
using namespace std;

int main() {
    string line;
    using bs = bitset<50>;

    vector<bs> reach;

    getline(cin, line);
    int m, n;
    stringstream ss(line);
    ss >> m >> n;

    vector<vector<int>> swtch(m);
    getline(cin, line);

    for (int i = 0; i < m; ++i) {
        getline(cin, line);
        stringstream ss(line);
        int x;
        while (ss >> x) {
            swtch[i].push_back(x);
        }
    }
    getline(cin, line);
    getline(cin, line);
    ss = stringstream(line);
    bs goal;
    for (int i = 0; i < n; ++i) {
        int j;
        ss >> j;
        if (j) goal.set(i);
    }

    int ans = 0;
    for (int mask = 0; mask < (1<<m); ++mask) {
        bs cur;
        for (int j = 0; j < m; ++j) {
            if ((mask >> j) & 1) {
                for (int i : swtch[j]) {
                    cur.flip(i);
                }
            }
        }
        ans += (cur == goal);
    }
    cout << ans << endl;
}
