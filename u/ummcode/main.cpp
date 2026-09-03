#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;

    string ums;
    while (cin >> s) {
        bool ok=1;
        for (char c : s) {
            if (isalnum(c) && c != 'u' && c != 'm') {
                ok=0;
                break;
            }
        }
        if (!ok) continue;
        for (char c : s) {
            if (c == 'u' || c == 'm')ums.push_back(c);
        }
    }

    for (int i = 0; i < ums.length(); i += 7) {
        int val = 0;
        for (int j = 0; j < 7; ++j) {
            if (ums[i+j] == 'u') {
                val |= 1<<(6-j);
            }
        }

        cout << (char)val;
    }
    cout << endl;
}
