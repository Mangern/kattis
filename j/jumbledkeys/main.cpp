#include <bits/stdc++.h>
using namespace std;

int main() {
    char mapping[256];
    memset(mapping, 0, sizeof mapping);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string s, t;
        cin >> s >> t;

        for (int j = 0; j < s.length(); ++j) {
            mapping[s[j]] = t[j];
        }
    }
    char x = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
        x ^= c;
        x ^= mapping[c];
    }
    for (char c = 'a'; c <= 'z'; ++c) {
        if (!mapping[c])mapping[c] = x;
    }


    string s;
    cin >> s;
    for (char c : s)cout << mapping[c];
    cout << endl;
}
