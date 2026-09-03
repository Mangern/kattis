#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T-->0) {
        int a, b;
        cin >> a >> b;

        int n, m;
        cin >> n >> m;

        vector<pair<int,int>> pos(n);
        vector<int> dir(n);
        vector<pair<int,int>> dx = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0}
        };
        for (int i = 0; i < n; ++i) {
            cin >> pos[i].first >> pos[i].second;
            char c;
            cin >> c;
            switch(c) {
                case 'N':
                    dir[i] = 0;
                    break;
                case 'E':
                    dir[i] = 1;
                    break;
                case 'S':
                    dir[i] = 2;
                    break;
                case 'W':
                    dir[i] = 3;
                    break;
            }
        }

        bool fail = 0;
        for (int _ = 0; _ < m; ++_) {
            int idx;
            cin >> idx, --idx;
            char act;
            cin >> act;
            int cnt;
            cin >> cnt;

            if (fail)continue;

            int result=-1;
            for (int r = 0; r < cnt; ++r) {
                if (act == 'F') {
                    pos[idx].first += dx[dir[idx]].first;
                    pos[idx].second += dx[dir[idx]].second;

                    auto [x, y] = pos[idx];
                    if (x < 1 || x > a || y < 1 || y > b) {
                        result = -2;
                        break;
                    }

                    for (int j = 0; j < n; ++j) if (j != idx) {
                        if (pos[j] == pos[idx]) {
                            result = j;
                            break;
                        }
                    }
                    if (result != -1) break;
                } else if (act == 'L') {
                    dir[idx] += 3;
                    dir[idx] %= 4;
                } else if (act == 'R') {
                    dir[idx] += 1;
                    dir[idx] %= 4;
                }
            }


            if (result == -2) {
                cout << "Robot " << idx+1 << " crashes into the wall" << endl;
                fail=1;
            } else if (result >= 0) {
                cout << "Robot " << idx+1 << " crashes into robot " << result+1 << endl;
                fail=1;
            }
        }
        if (!fail)cout << "OK" << endl;
    }
}
