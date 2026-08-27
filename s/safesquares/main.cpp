#include <bits/stdc++.h>
using namespace std;

using ii = pair<int,int>;

int main() {
    set<ii> safe;
    for (int i = 0; i < 8; ++i) for (int j = 0; j < 8; ++j)safe.insert({i,j});

    for (int i = 0; i < 8; ++i) {
        string s;
        cin >> s;


        for (int j = 0; j < 8; ++j) {
            if (s[j] == 'R') {
                for (int r = 0; r < 8; ++r) {
                    safe.erase({r, j});
                }

                for (int c = 0; c < 8; ++c) {
                    safe.erase({i,c});
                }
            }
        }
    }

    cout << safe.size() << endl;
}
