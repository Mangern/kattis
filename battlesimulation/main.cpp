#include <bits/stdc++.h>
using namespace std;

bool check(const string& s, int i) {
    if (i + 2 >= s.length()) return false;
    int v = s[i] ^ s[i+1] ^ s[i+2];

    return v == int('R' ^ 'B' ^ 'L');
}

int main() {
    string s;
    cin >> s;
    int n = s.length();

    for (int i = 0; i < n; ) {
        if (check(s,i)) {
            cout << 'C';
            i += 3;
        } else {
            if (s[i] == 'R')cout << 'S';
            if (s[i] == 'B')cout << 'K';
            if (s[i] == 'L')cout << 'H';
            ++i;
        }
    }
    cout << endl;
}
