#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<string> pl;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        pl.push_back(s);
    }

    while (q-->0) {
        string cmd;
        cin >> cmd;

        if (cmd[0] == 'P') {
            int i;
            cin >> i, --i;
            string letters;
            cin >> letters;

            bool ok=1;
            for (char c : letters) {
                if (pl[i].find(c) == string::npos) {
                    ok=0;
                }
            }
            cout << (ok?"YES":"NO") << '\n';
        } else {
            int x, i, z;
            cin >> x >> i >> z;
            --x, --i, --z;

            char c = pl[x][i];
            pl[x].erase(pl[x].begin() + i);
            pl[z].push_back(c);
        }
    }
}
