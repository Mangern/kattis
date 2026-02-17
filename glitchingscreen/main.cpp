#include <bits/stdc++.h>
using namespace std;
using bs = bitset<10005>;

int main() {
    int h, w, n;
    cin >> h >> w >> n;

    vector<bs> db(n);

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < h; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < w; ++j) {
                if (s[j] == 'x') {
                    db[k].set(i * w + j);
                }
            }
        }
    }

    bs query;
    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < w; ++j) {
            if (s[j] == 'x') {
                query.set(i * w + j);
            }
        }
    }

    int cnt = 0;
    for (auto &b : db) {
        if ((b & query) == query) {
            ++cnt;
        }
    }
    cout << (cnt == 1 ? "yes":"no") << endl;
}
