#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    string s(n, '?');

    bool fail = 0;
    while (q-->0) {
        int idx;
        string t;
        cin >> idx >> t, --idx;

        for (int i = 0; i < t.length(); ++i) {
            if (s[idx+i] != '?' && s[idx+i] != t[i]) {
                fail = 1;
            }
            s[idx+i] = t[i];
        }
    }
    if (fail) {
        cout << "Villa" << endl;
    } else {
        cout << s << endl;
    }
}
