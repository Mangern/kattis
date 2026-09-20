#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int T;
    cin >> T;

    while (T-->0) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        vector<int> cnt(256, 0);
        for (char c : s)++cnt[c];

        vector<ll> waitc(256, -1);
        vector<ll> wait(n,0);

        int tptr = n - 1;
        string t(n,'?');
        ll swait = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (waitc[s[i]] == -1) {
                waitc[s[i]] = i;
            }
            swait += waitc[s[i]];

            for (int j = 0; j < cnt[s[i]]; ++j) {
                t[tptr--] = s[i];
            }
            cnt[s[i]] = 0;
        }
        waitc.assign(256, -1);

        ll nwait = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (waitc[t[i]] == -1) {
                waitc[t[i]] = i;
            }
            nwait += waitc[t[i]];
        }

        cout << 5 * (swait - nwait) << endl;
    }
}
