#include <bits/stdc++.h>
using namespace std;

const int mxN = 105;

int n, e;
bitset<50> know[mxN];

int main() {
    cin >> n >> e;
    int cur=0;
    for (int i = 0; i < e; ++i) {
        int k;
        cin >> k;
        vector<int> pres(k);
        for (auto &x : pres) {
            cin >> x, --x;
        }
        sort(begin(pres), end(pres));

        if (pres[0] == 0) {
            for (int i : pres) {
                know[i].set(cur);
            }
            cur++;
            continue;
        }

        bitset<50> res = know[pres[0]];

        for (int i : pres) {
            res |= know[i];
        }

        for (int i : pres) {
            know[i] = res;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (know[i].count() == cur)cout << i+1 << "\n";
    }
}
