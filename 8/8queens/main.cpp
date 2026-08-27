#include <bits/stdc++.h>
using namespace std;
using ii = array<int, 2>;

int main() {
    int n = 0;

    vector<ii> loc;

    for (int i = 0; i < 8; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < 8; ++j) {
            if (s[j] == '*') {
                loc.push_back({i, j});
                ++n;
            }
        }
    }

    if (n != 8) {
        cout << "invalid" << endl;
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            auto [x1, y1] = loc[i];
            auto [x2, y2] = loc[j];

            if (x1 == x2 || y1 == y2 || x1+y1==x2+y2 || x1-y1 == x2-y2) {
                cout << "invalid" << endl;
                return 0;
            }
        }
    }
    cout << "valid" << endl;
}
