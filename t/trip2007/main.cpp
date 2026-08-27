#include <bits/stdc++.h>
using namespace std;

int main() {
    for (;;) {
        int n;
        cin >> n;
        if (!n) break;

        vector<int> a(n);
        map<int, int> freq;
        for (auto& x : a) {
            cin >> x;
            ++freq[x];
        }

        int ans = 0;
        for (auto [k, v] : freq)ans = max(ans, v);
        
        vector<vector<int>> bag(ans);

        for (auto &[k, v] : freq) {
            if (v == ans) {
                v = 0;
                for (auto &b : bag)b.push_back(k);
            }
        }

        sort(begin(a), end(a));

        int bptr = 0;
        for (auto x : a) if (freq[x]) {
            bag[bptr].push_back(x);
            if (++bptr == ans)bptr = 0;
        }
        cout << ans << endl;
        for (auto &b : bag) {
            for (auto x : b) cout << x << " ";
            cout << endl;
        }
    }
}
