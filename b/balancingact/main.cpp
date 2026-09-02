#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    auto check = [](const string& t) {
        int d = 0;
        for (char c : t) {
            if (c == '(') {
                ++d;
            } else if (!d) {
                return false;
            } else --d;
        }
        return d == 0;
    };

    for (int mask = 0; mask < (1<<n); ++mask) {
        string t = s;

        for (int i = 0; i < n; ++i) {
            if (t[i] == '*') {
                if ((mask >> i) & 1) {
                    t[i] = '(';
                } else {
                    t[i] = ')';
                }
            }
        }

        if (check(t)) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}
