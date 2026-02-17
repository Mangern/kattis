#include <bits/stdc++.h>
using namespace std;
using tup = array<int, 3>;

int main() {
    string line;
    for (;;) {
        vector<tup> tris(6);
        for (auto &t : tris) {
            getline(cin, line);
            if (line == "*") {
                getline(cin, line);
            } else if (line == "$") return 0;
            stringstream ss(line);
            for (auto &x : t) {
                ss >> x;
                if (!x) return 0;
            }
        }
        sort(begin(tris), end(tris));
        vector<tup> ntris(6);

        int ans = 0;
        do {
            for (int mask = 0; mask < 729; ++mask) {
                int x = mask;
                for (int i = 0; i < 6; ++i) {
                    auto [t1, t2, t3] = tris[i];
                    if (x % 3 == 0) {
                        ntris[i] = {t1, t2, t3};
                    } else if (x % 3 == 1) {
                        ntris[i] = {t2, t3, t1};
                    } else {
                        ntris[i] = {t3, t1, t2};
                    }
                    x /= 3;
                }
                bool ok = 1;
                int sm = 0;
                for (int i = 0; i < 6; ++i) {
                    if (ntris[i][0] != ntris[(i+1)%6][1])ok=0;
                    sm += ntris[i][2];
                }
                if (ok) ans = max(ans, sm);
            }
        } while (next_permutation(begin(tris), end(tris)));
        if (!ans) cout << "none" << endl;
        else cout << ans << endl;
    }
}
