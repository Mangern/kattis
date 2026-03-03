#include <bits/stdc++.h>
using namespace std;

int main() {
    for (;;) {
        int n;
        cin >> n;
        if (!n) return 0;
        int m;
        cin >> m;
        int k;
        cin >> k;
        string s;
        cin >> s;

        s = '$' + s;

        vector<int> loc(n,0);
        int cur = 0;

        bool ok=0;
        for (int i = 0; i < k; ++i) {
            string t;
            cin >> t;
            if (ok) continue;

            int its = t.length();
            for (int j = 0; j < its; ++j) {
                int nxt = s.find(t[j], loc[cur] + 1);
                if (nxt == string::npos || nxt == s.length() - 1) {
                    cout << "Player " << cur+1 << " won after " << i+1 << " cards." << endl;
                    ok=1;
                }
                loc[cur] = nxt;
                // cout << "Player " << cur + 1 << " is now at card " << loc[cur] << endl;
            }

            cur = (cur + 1) % n;
        }

        if (!ok) {
            cout << "No player won after " << k << " cards." << endl;
        }
    }
}
