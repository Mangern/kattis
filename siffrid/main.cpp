#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    int sm = 0;
    for(char c : s)sm += c - '0';

    string lo(n, '0');
    int lorem = sm - 1;
    lo[0] = '1';
    while (lorem > 9 * (n - 1)) {
        --lorem;
        ++lo[0];
    }

    for (int i = 1; i < n; ++i) {
        int j;
        for (j = 0; j < 10; ++j) {
            if (lorem - j <= 9 * (n - i - 1))break;
        }
        lo[i] = j + '0';
        lorem -= j;
    }

    string hi(n, '0');
    int hirem = sm;
    for (int i = 0; i < n; ++i) {
        int j;
        for (j = 9; j >= 0; --j) {
            if (hirem - j >= 0) break;
        }
        hi[i] = j + '0';
        hirem -= j;
    }

    cout << lo << " " << hi << endl;
}
