#include <bits/stdc++.h>
using namespace std;

int main() {
    for (;;) {
        int n, p, s;
        cin >> n;
        if (!n)break;
        cin >> p >> s;

        vector<int> sz(n);
        for (auto &x: sz)cin >> x;

        vector<pair<int, string>> prog(p);
        for (auto &[x, s] : prog)cin >> x >> s;


        vector<int> ref(20, 0);

        int cur = 0;
        int ans = 0;
        for (int i = 0; i < s; ++i) {
            int q;
            cin >> q;

            if (q>0) {
                q--;
                auto &[ps, dll] = prog[q];
                cur += ps;

                for (char c : dll) {
                    if (!ref[c-'A']++) {
                        cur += sz[c-'A'];
                    }
                }
                ans=max(ans,cur);
            } else {
                q=(-q)-1;
                auto &[ps, dll] = prog[q];
                cur -= ps;

                for (char c : dll) {
                    if (!--ref[c-'A']) {
                        cur -= sz[c-'A'];
                    }
                }
            }
        }
        cout << ans << endl;
    }
}
