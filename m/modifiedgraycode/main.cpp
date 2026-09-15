#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> gc(1, string(10, '0'));
    unordered_set<string> have;
    have.insert(gc[0]);

    for (int i = 0; i < 500; ++i) {
        string best;
        for (int mask = 0; mask < (1<<10); ++mask) {
            if (__builtin_popcount(mask) % 2 != 0) continue;
            string nxt = gc.back();

            for (int j = 0; j < 10; ++j) {
                if ((mask >> j) & 1) {
                    nxt[j] ^= '0' ^ '1';
                }
            }

            if (have.count(nxt))continue;
            if (best.empty() || nxt < best) {
                best = nxt;
            }
        }
        gc.push_back(best);
        have.insert(best);
    }

    int q;
    cin >> q;
    while (q-->0) {
        int i;
        cin >> i;
        cout << gc[i] << '\n';
    }
}
